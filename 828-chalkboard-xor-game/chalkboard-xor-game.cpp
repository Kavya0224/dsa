class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int xor_sum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            xor_sum ^= nums[i];
        }
        
        vector<int> vis(nums.size(), 0);
        int turn = 0; // 0 for Alice, 1 for Bob
        
        if(xor_sum == 0) return true;
        
        while(true){
            int f = 0;
            for(int i = 0; i < nums.size(); i++){
                // Added parentheses around the XOR operation
                if(!vis[i] && (nums[i] ^ xor_sum) != 0){ 
                    xor_sum ^= nums[i]; // Update the running XOR sum!
                    vis[i] = true;
                    f = 1;
                    break;
                }
            }
            
            // If a player cannot make a valid move, they lose
            if(f == 0) {
                return turn == 1; // If it's Bob's turn (1) and he fails, Alice wins (true)
            }
            
            turn = 1 - turn;
        }
        return false;
    }
};