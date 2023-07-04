/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
//public:
void sortedInsert(stack<int>&s,int num)
{
   if(s.empty()||(!s.empty()&&s.top()<num))
   {
       s.push(num);
       return;
   }
   //side me element ko nikal lo
   int store=s.top();
   s.pop();
   
   //rec call
   sortedInsert(s,num);
   
   //vapas jate waqt jo elem nikala tha use vapis daal do
   s.push(store);
   
}

void SortedStack :: sort()
{
   //base case
   if(s.empty())
   {
      return;
   }
   
   int num=s.top();
   s.pop();
   
   //rec call
   sort();
   
   //vapas aate waqt sorted way me insert karna hai
   sortedInsert(s,num);
   
}