import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Stack;


public class BST<E extends Comparable<E>> {

	protected TreeNode<E> root;
	protected int size = 0;
	
	public BST() { }
	
	public BST(E[] objects) {
		for (int i=0; i<objects.length; i++) {
			insert(objects[i]);
		}
	}
	
	public boolean search(E e) {
		TreeNode<E> current = root;
		
		while (current != null) {
			if (e.compareTo(current.element) < 0) {
				current = current.left;
			} else if (e.compareTo(current.element) > 0) {
				current = current.right;
			} else {
				return true;
			}
		}
		
		return false;
	}
	
	public boolean insert(E e) {
		if (root == null) {
			root = createNewNode(e);
		} else {
			TreeNode<E> parent = null;
			TreeNode<E> current = root;
			while (current != null) {
				if (e.compareTo(current.element) < 0) {
					parent = current;
					current = current.left;
				} else if (e.compareTo(current.element) > 0) {
					parent = current;
					current = current.right;
				} else {
					return false;
				}
			}
				
			if (e.compareTo(parent.element) < 0) {
				parent.left = createNewNode(e);
			} else {
				parent.right = createNewNode(e);
			}
		}
		
		size++;
		return true;
	}
	
	protected TreeNode<E> createNewNode(E e) {
		return new TreeNode<E>(e);
	}
	
	public void inorder() {
		inorder(root);
	}
	
	protected void inorder(TreeNode<E> root) {
		if (root == null) return;
		inorder(root.left);
		System.out.print(root.element + " ");
		inorder(root.right);
	}
	
	public void postorder() {
		postorder(root);
	}
	
	protected void postorder(TreeNode<E> root) {
		if (root == null) return;
		postorder(root.left);
		postorder(root.right);
		System.out.print(root.element + " ");
	}
	
	public void preorder() {
		preorder(root);
	}
	
	protected void preorder(TreeNode<E> root) {
		if (root == null) return;
		System.out.print(root.element + " ");
		preorder(root.left);
		preorder(root.right);
	}
	
	public int getSize() {
		return size;
	}
	
	public TreeNode<E> getRoot() {
		return root;
	}
	
	public ArrayList<TreeNode<E>> path(E e) {
		ArrayList<TreeNode<E>> list = new ArrayList<>();
		TreeNode<E> current = root;
		
		while (current != null) {
			list.add(current);
			if (e.compareTo(current.element) < 0) {
				current = current.left;
			} else if (e.compareTo(current.element) > 0) {
				current = current.right;
			} else {
				break;
			}
		}
		
		return list;
	}
	
	public boolean delete(E e) {
		TreeNode<E> parent = null;
		TreeNode<E> current = root;
		
		while (current != null) {
			if (e.compareTo(current.element) < 0) {
				parent = current;
				current = current.left;
			} else if (e.compareTo(current.element)> 0) {
				parent = current;
				current = current.right;
			} else {
				break;
			}
		}
		
		if (current == null) {
			return false;
		}
		
		if (current.left == null) {
			if (parent == null) {
				root = current.right;
			} else {
				if (e.compareTo(parent.element) < 0) {
					parent.left = current.right;
				} else {
					parent.right = current.right;
				}
			}
		} else {
			TreeNode<E> parentOfRightMost = current;
			TreeNode<E> rightMost = current.left;
			
			while (rightMost.right != null) {
				parentOfRightMost = rightMost;
				rightMost = rightMost.right;
			}
			
			current.element = rightMost.element;
			
			if (parentOfRightMost.right == rightMost) {
				parentOfRightMost.right = rightMost.left;
			} else {
				parentOfRightMost.left = rightMost.left;
			}
		}
		
		size--;
		return true;
	}
	
	public Iterator<E> iterator() {
		return new InorderIterator();
	}
	
	public void clear() {
		root = null;
		size = 0;
	}
	
	/* Displays the nodes in a breadth-first traversal */
	public void breadthFirstTraversal() {
		List<TreeNode<E>> list = new ArrayList<TreeNode<E>>();
		if (root != null) {
			list.add(root);
			TreeNode<E> present;
			while (!list.isEmpty()) {
				present = (TreeNode<E>) list.remove(0);
				System.out.print(present.element + " ");
				if (present.left != null) {
					list.add(present.left);
				}
				if (present.right != null) {
					list.add(present.right);
				}
			}
		}
	}// end of breadthFirstTraversal method

	/* Returns the height if this binary tree */
	public int height() {
		return height(root);
	}
	private int height(TreeNode<E> root) {
		if (root == null) {
			return 0;
		} 
		else {
			return 1 + Math.max(height(root.left), height(root.right));
		}
	}// end of height method

	/* inorder using stack instead of recursion */
	public void inorderUsingtack() {
		inorderUsingStack(root);
		}// end of inOrderUsingStack method
		
	private void inorderUsingStack(TreeNode<E> root) {
		Stack<TreeNode<E>> stack = new Stack<TreeNode<E>>();
		while (!stack.isEmpty() || root != null) {
			if (root != null) {
				stack.push(root);
				root = root.left;
			} 
			else {
				root = stack.pop();
				System.out.print(root.element + " ");
				root = root.right;
			}
		}
	}//end of inOrderUsingStack method
	
	private class InorderIterator implements Iterator<E> {
		
		private ArrayList<E> list = new ArrayList<>();
		private int current = 0;
		
		public InorderIterator() {
			inorder();
		}
		
		private void inorder() {
			inorder(root);
		}
		
		private void inorder(TreeNode<E> root) {
			if (root == null) return;
			inorder(root.left);
			list.add(root.element);
			inorder(root.right);
		}
		
		public boolean hasNext() {
			return current < list.size();
		}
		
		public E next() {
			return list.get(current++);
		}
		
		public void remove() {
			delete(list.get(current));
			list.clear();
			inorder();
		}
	}
}
