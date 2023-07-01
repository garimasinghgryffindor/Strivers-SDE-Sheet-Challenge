1: approach using brute-force (normal sorting)

2: approach using variables to keep a count of 1’s 0’s and 2’s

3: approach using a two-pointer approach Dutch National Flag Algorithm


// OPTIMAL
// DUTCH NATIONAL FLAG ALGORITHM
// TWO POINTER APPROACH
void sort012(int *arr, int n)
{
   int low = 0, mid = 0, high = n-1;

   // low => positions of 0s
   // mid => positions of 1s
   // high => positions of 2s

   while(mid <= high) {
      // if current element is 0
      if(arr[mid] == 0) {
         swap(arr[mid], arr[low]);
         mid++;
         low++;
      } else if(arr[mid] == 1) {
         // if current element is 1
         mid++;
      } else {
         swap(arr[mid], arr[high]);
         high--;
      }
   }
}
