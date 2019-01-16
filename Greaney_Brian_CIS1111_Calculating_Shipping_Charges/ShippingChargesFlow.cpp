#include <iostream>
#include <string>

using namespace std;
int main()
{
   string raptor_prompt_variable_zzyz;
   ?? distanceremainder;
   ?? rate1;
   ?? rate2;
   ?? rate3;
   ?? totaldistance;
   ?? shippingrate;
   ?? distance;
   ?? shippingweight;
   ?? shippingdistance;
   ?? rate4;
   ?? totalbill;

   rate1 =1.1;
   rate2 =2.2;
   rate3 =3.7;
   rate4 =4.8;
   raptor_prompt_variable_zzyz ="Please enter the weight in pounds of your package";
   cout << raptor_prompt_variable_zzyz << endl;
   cin >> shippingWeight;
   raptor_prompt_variable_zzyz ="Please enter the distance in miles of your shipment";
   cout << raptor_prompt_variable_zzyz << endl;
   cin >> shippingDistance;
   distance =shippingDistance/500;
   distanceRemainder =(distance % 500+500) % 500;
   totalDistance =distance+distanceRemainder;
   if (shippingWeight<5)
   {
      shippingRate =rate1;
   }
   else
   {
      if (shippingWeight<15)
      {
         shippingRate =rate2;
      }
      else
      {
         if (shippingWeight<30)
         {
            shippingRate =rate3;
         }
         else
         {
            if (shippingWeight<50)
            {
               shippingRate =rate4;
            }
            else
            {
            }
         }
      }
   }
   cout << "Your Shipping rate is: "+shippingRate << endl;   cout << "Number of 500 mile segments ="+totalDistance << endl;   totalBill =totalDistance*shippingRate;
   cout << "Your total cost is: $"+totalBill << endl;
   return 0;
}
