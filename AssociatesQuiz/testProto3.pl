###########################################################
# Test prototype for associates quizzes
#  prototype #3
#
#
###########################################################
use DBI;
use Data::Dumper;
require 'associateconnection.pl';
require '/include/CGI-lib.pl';
require '/include/cookie.lib';
require 'log.asp';
&ReadParse;
&GetCookies;
&GetVerbosity;
my $badge = $Cookies{session};
my $id = $Cookies{associatenum};
my $firstname = $Cookies{firstname};
my $lastname = $Cookies{lastname};
my $messages = $Cookies{messages};
my $dept_desc = $Cookies{deptdesc};
my $username = $Cookies{username};
&printHeader("home","$id");

my $dsn = "DBI:ODBC:Playground";
my $dbh = DBI->connect($dsn, "user", "password");
my $pass = 0;
if($in{submit}){
	# Create a variable to hold the total number of answers
	my $total = 0;
	# Create a variable to hold the number of correctly answered questions
	my $correct = 0;
	my $testID = $in{test};
	my $associateID = $id;
	my @wrongAnswers;
	foreach my $answer (sort keys %in){
		if($answer =~ /questionAnswer_(\d+)/){
			my $selectedID = $1;
			my $compareAnswer = $dbh->prepare("
				SELECT CorrectAnswer
				FROM Answers
				WHERE ID=?
			");
			if($compareAnswer->execute($in{$answer})){
				my ($isCorrect) = $compareAnswer->fetchrow_array();
				# If the answer was correct, increase the correct count
				if($isCorrect){
					$correct++;
				}
				else{
					push @wrongAnswers, $total+1;
				}
			}               
			# Regardless, increase the total answer count
			$total++;
		}
	}
	# If the number of answers matches the number of correct answers, they passed
	if($total == $correct && $total != 0){
		$ans = "Pass";
		$pass = 1;
		&updateResults($testID ,$associateID, $pass);
		$message = "<b>You passed the test!</b>";
		$messageType = "success";
	}
	else{
		$ans = "Fail";
		$pass = 0;
		&updateResults($testID ,$associateID, $pass);
		my $missed = join(', #', @wrongAnswers);
		$missed =~ s/(.+),(.+?)$/$1 &$2/;
		$message = "<b>You failed the test! TRY HARDER! you missed question(s): #$missed</b>";
		$messageType = "error";
	}
	if ($message ne ""){
		$alert = "<div id='alert' class='$messageType ui-corner-all'>$message</div>";
	}
}

print <<"END_HTML";
<style>
	#maincontentTests {
		width: 100%;
		max-width: 900px;
		margin: 0 auto;
		clear: both;
		overflow: auto;
	}
	hr{
		border-color: #201747;
	}
	.blueText{
		font-family: Arial, Helvetica, Verdana, sans-serif;
		text-transform: uppercase;
		font-size: .85em;
		font-weight: bold;
		color: #001e60;  /*French Blue*/
	}
	.flexContainer{
		display: flex;
		flex-flow: row wrap;
		justify-content: space-between;
		padding: 0 15px;
	}
	.centered {
		display: inline-block;
		background-color: #c2b2b5;
		width: 30%;
		border: 4px solid #201747;
		box-shadow: 6px 6px;
		padding: 10px;
		flex-grow: 0;
		flex-shrink: 1;
		flex-basis: inherit;
		margin: 10px;
	}
	.tButton{
		text-align:center;
		bottom: 10px;
		left:0;
		right:0;
	}
	input[type=submit] {
		padding: 10px;
		box-shadow: 6px 6px;
		width: 15em;  
		height: 3em;
		font: bold;
		text-transform: uppercase;
	}	
</style>
<div id="maincontentTests">
$alert
END_HTML
if (defined $in{class}){
	my $testID = $in{class};
	my $associateID = $id;
	my $checker = &checkTest($testID, $associateID);
	my $goBack = "<input type='button' style='border-radius: 12px; font-size: 15px; background-color: #c2b2b5;
			color: black;' value='BACK TO TRAINING' onclick='window.location.href=\"http://associate.portal/test_proto3a.pl\"' />";
	my $getBody = $dbh->prepare("
		SELECT Body
		FROM Tests
		WHERE ID = ?
	");
	if($getBody->execute($testID)){
		while(($body) = $getBody->fetchrow_array()){
			print "$body";
		}
	}
	if ($checker == 0){
		print <<"END_HTML";
		</div>
		<br>
		<div class="tButton">
			<input type="button" value="&#9755; Take the test " 
				onclick="window.location.href='http://associate.portal/test_proto3a.pl?test=$testID'">
			<br>
			<br>
			<div>$goBack</div>			
		</div>
END_HTML
	}
	else{
		print <<"END_HTML";
		</div>
		<br>
		<div class="tButton">
			<h2 class="centered">Congratulations, it appears you've already passed this course!</h2>
			<br>
			<br>
			<div>$goBack</div>			
		</div>
END_HTML
	}
	&printFooter;
	exit(1);
		
}
if (defined $in{test} && $pass != 1){
	my $testID = $in{test};
	my $associateID = $id;
	my $checker = &checkTest($testID, $associateID);
	if ($checker == 1){
		print <<"END_HTML";
			<div id="flex" class="flexContainer">
				<div class="centered" style="text-align=center;">
					<h1>You have already passed this test</h1>
					<h2>
						<a href="http://associate.portal/test_proto3a.pl">Click here to try another test</a>
					</h2>
				</div>
			</div>
		</div>
END_HTML
		&printFooter;
		exit(1);
	}
	my @questions;
	my $getTest = $dbh->prepare("
		SELECT ID, Name
		FROM Tests
	");
	my $getQuestion = $dbh->prepare("
		SELECT ID, Question 
		FROM Questions
		WHERE TestID = ? AND Deleted = 0
	");
	$getQuestion->execute($testID);
	while(my @question = $getQuestion->fetchrow_array()){
		push(@questions, \@question);
	}
	my $sth = $dbh->prepare("
		SELECT ID, AnswerText, CorrectAnswer
		FROM Answers
		WHERE QuestionID = ?
		ORDER BY SortOrder
	");
	my $ans;

	print <<"END_HTML";	
		<form method="post" action="/test_proto3a.pl">
		<div id="flex" class="flexContainer">
END_HTML
	my $limit = scalar @questions;
	for(my $i = 0; $i < $limit; $i++){
		my $qCount = $i+1;
		my $qID = $questions[$i][0];
		print <<"END_HTML";
		<div id="question-$questions[$i][0]"  class="centered">
			<p class="text-center"><strong>Question &num;$qCount</strong></p>
			<p class="text-center" ><strong>$questions[$i][1]</strong></p></br>
					<table>						
END_HTML
		if($sth->execute($questions[$i][0])){
			$num = 1;
			while(($ansID, $ansText, $correct) = $sth->fetchrow_array()){
				print <<"END_HTML";
				<tr>
				<td style="padding: 15px 30px">	
					<label>
						<input type="radio" name="questionAnswer_$qID" id="$ansID" value="$ansID" required="required"/>
						<span style="font-size: 12px;">$num. $ansText</span>
					</label>
				</td>
				</tr>
END_HTML
				$num++;
			}
		}
		print <<"END_HTML";
					</table>
				</div>
END_HTML
	}
	my $submitButton = "";
	my$restartButton = "";
	if($limit!=0){
		$submitButton = "<input type='submit' name='submit' value='Submit'/>";
		$restartButton = "<input type='button' style='border-radius: 12px; font-size: 20px; background-color: #c2b2b5;
			color: black;' value='START OVER!' onclick='window.location.href=\"http://associate.portal/test_proto3a.pl\"' />";
	}
	print <<"END_HTML";
	</div>
		<div class="tButton">
			$submitButton
			<input type="hidden" name="test" value="$in{test}" />
		</div>
		<div class="text-center">
			<h1>$ans</h1>
		</div>
		<!-- $restartButton -->
		</form>
END_HTML
	&printFooter;
	exit(0);
}

print <<"END_HTML";
<div id="jobpostings">
	<h1>Associate Training</h1>
	<p>Welcome to Associate Training, here you will be able to learn about Dorothy Lane Market and all of its 
		different departments. Choosing a course will take you to a learning page where you will be able to discover 
		all of the inner workings department by department. After reviewing the provided material, you will be asked 
		to take a quiz on the material you have just reviewed. Upon completion you will be notified whether or not you 
		passed the quiz. Do not worry if you do not pass it the first time, review the materials and take it again. 
		If you receive a passing grade you are still free to review the course material anytime, but the quiz will 
		no longer be available to you. Good luck! 
	</p>
</div>
END_HTML
my @availableTests = &getTests(0);
if (@availableTests){
	print <<"END_HTML";
	<div id="jobpostings">
		<h2>Available Tests</h2>
		<hr>
	</div>
	<div class="flexContainer">
END_HTML
	&displayTests(@availableTests);
	print <<"END_HTML";
	</div>
END_HTML
}
my @reviewTests = &getTests(1);
if (@reviewTests){
	print <<"END_HTML";
	<div id="jobpostings">
		<h2>Review</h2>
		<hr>
	</div>
	<div class="flexContainer">
END_HTML
	&displayTests(@reviewTests);
	print <<"END_HTML";
	</div>
END_HTML
}
print <<"END_HTML";
	</div>
</div>
END_HTML
&printFooter;

sub updateResults{
	my ($testID, $associateID, $pass) = @_;
	my $testResults = $dbh->prepare("
		INSERT INTO Results(TestID, AssociateID, Passed)
		VALUES (?, ?, ?)
	");
	$testResults->execute($_[0] , $_[1], $_[2]);
}
sub checkTest{
	my ($testID, $assID) = @_;
	my $passing = 0;
	my $check = $dbh->prepare("
		SELECT TestID, AssociateID, Passed
		FROM Results
		WHERE TestID=? AND AssociateID=?
	");
	if($check->execute($_[0], $_[1])){
		while(@record = $check->fetchrow_array()){
			if ($record[2] == 1){
				$passing++;
			}
			elsif($record[2] == 0){
				$passing = 0;
			}
			else{
				return;
			}	
		}
	}
	if ($passing > 0){
		return 1;
	}
	else{ 
		return 0;
	}
}
sub getTests{
	my $marker = shift;
	my $id = $Cookies{associatenum};
	my $getTestList = $dbh->prepare("
		SELECT Tests.ID, Name, CreatedBy, UpdatedOn, ShortDescription, Body, questions.Count
		FROM Tests
			JOIN(
				SELECT TestID, COUNT(*) AS Count
				FROM Questions
				WHERE Deleted=0
				GROUP BY TestID
			) AS questions ON questions.TestID = Tests.ID
			LEFT JOIN Results ON Tests.ID = Results.TestID AND Results.AssociateID = ?
		GROUP BY Tests.ID, Name, CreatedBy, UpdatedOn, ShortDescription, Body, questions.Count
		HAVING SUM(ISNULL(Results.Passed,0)) = ?
		ORDER BY Tests.ID ASC
	");
	my @tests;
	if($getTestList->execute($id,$marker)){
		while(my @test = $getTestList->fetchrow_array()){
			push(@tests, \@test);
		}
	}
	return @tests;
}
sub displayTests{
	my @test = @_;
	my $limiter = scalar @test;
	for(my $i=0; $i< $limiter; $i++){
		print <<"END_HTML";
		<div class="centered">
			<h1 style="text-align:center;">$test[$i][1]</h1>
			<hr>
			<p class="blueText">$test[$i][4]</p>
			<br>
			<p>Number of questions: $test[$i][6]</P>
			<div class="tButton">
				<input type="button" value="&#9755; Start " 
					onclick="window.location.href='http://associate.portal/test_proto3a.pl?class=$test[$i][0]'">
			</div>
		</div>
END_HTML
	}
}
