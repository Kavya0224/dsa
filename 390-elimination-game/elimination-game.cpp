// // class Solution {
// // public:
// // void helper(int n,int i,vector<int>& arr,int per){
// //     if(arr.size()==1) return;
// //     if(i>=arr.size()){
// //         if(per==1) per=0;
// //         else per=1;
// //         return;
// //     } 
// //     arr.erase(arr.begin()+i);
// //     if(per%2==0){
// //         helper(n,i+1,arr,per);
// //     }
// //     else{
// //         if(i>=1) helper(n,i+1,arr,per);
// //         else helper(n,1,arr,per);
// //     }
    
// // }
// //  int lastRemaining(int n) {
// //     vector<int> arr;
// //     for(int i=0;i<n;i++){
// //         arr.push_back(i+1);
// //     }
// //         helper(n,0,arr,0);
// //         return arr[0];
// //     }
// // };
// class Solution {
// public:
//     void helper(vector<int>& arr, bool leftToRight) {
//         if (arr.size() == 1) return;

//         vector<int> next;
//         int n = arr.size();

//         if (leftToRight) {
//             for (int i = 1; i < n; i += 2) {
//                 next.push_back(arr[i]);
//             }
//         } else {
//             // From right to left: remove last, third-last, etc.
//             for (int i = n - 2; i >= 0; i -= 2) {
//                 next.push_back(arr[i]);
//             }
//             reverse(next.begin(), next.end()); // Maintain ascending order
//         }

//         // Recursive call with flipped direction
//         helper(next, !leftToRight);
//         arr = next;
//     }

//     int lastRemaining(int n) {
//         vector<int> arr;
//         for (int i = 1; i <= n; ++i) {
//             arr.push_back(i);
//         }

//         helper(arr, true); // Start from left to right
//         return arr[0];
//     }
// };
class Solution {
public:
    int lastRemaining(int n) {
        if (n == 1) return 1;
        return 2 * (n / 2 + 1 - lastRemaining(n / 2));
    }
};