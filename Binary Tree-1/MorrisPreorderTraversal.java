/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
// class Solution {
//     public static void preorder(TreeNode root,ArrayList<Integer>ans){
//         if(root == null)
//         return;

//         ans.add(root.val);
//         preorder(root.left,ans);
//         preorder(root.right,ans);
//     }
//     public List<Integer> preorderTraversal(TreeNode root) {
//         ArrayList<Integer> ans = new ArrayList<Integer>();
//         preorder(root,ans);
//         return ans;

//     }
// }

//MORRIS TRAVERSAL
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        ArrayList<Integer> ans = new ArrayList<Integer>();
         TreeNode curr = root;

       while(curr != null){

           if(curr.left == null){
               ans.add(curr.val);
               curr = curr.right;
           }

           else{

               //finding inorder predecessor
               TreeNode pred = curr.left;
               while(pred.right != curr && pred.right != null){
                 pred = pred.right;
               }

               if(pred.right == null){
                   pred.right = curr;
                   ans.add(curr.val);
                   curr = curr.left;
               }

               else{
                   pred.right = null;
                   curr = curr.right;
               }
           }
       }
       return ans; 
    
    }
}