class Solution
{
    public:
    //comparator function to sort the Items value per weight wise
    bool static comparator(Item a,Item b){
        double valPerW1 = (double)a.value/(double)a.weight;
        double valPerW2 = (double)b.value/(double)b.weight;
        return valPerW1 > valPerW2;
        
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        //comparator
        sort(arr,arr+n,comparator);
        
        double currW = 0.0;
        double ansVal = 0.0;
        
        for(int i=0;i<n;i++){
            
            if(currW + arr[i].weight <= w){
                currW += arr[i].weight;
                ansVal += arr[i].value;
            }
            else{
                int remainingWeight = w - currW;
                ansVal += (arr[i].value/(double)arr[i].weight) * (double)remainingWeight;
                break;
            }
        }
       
       return ansVal; 
    }
        
};