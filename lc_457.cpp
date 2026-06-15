class Solution {
public:
    int nextIndex(vector<int>& nums, int i) {
        int n = nums.size();
        return ((i + nums[i]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;

            bool dir = nums[i] > 0;

            int slow = i;
            int fast = i;

            while (true) {
                int ns = nextIndex(nums, slow);
                int nf = nextIndex(nums, fast);

                if (nums[ns] == 0 || (nums[ns] > 0) != dir)
                    break;

                if (nums[nf] == 0 || (nums[nf] > 0) != dir)
                    break;

                nf = nextIndex(nums, nf);

                if (nums[nf] == 0 || (nums[nf] > 0) != dir)
                    break;

                slow = ns;
                fast = nf;

                if (slow == fast) {
                    if (slow == nextIndex(nums, slow))
                        break;

                    return true;
                }
            }

            // cleanup
            int curr = i;

            while (nums[curr] != 0 && (nums[curr] > 0) == dir) {
                int nxt = nextIndex(nums, curr);
                nums[curr] = 0;
                curr = nxt;
            }
        }

        return false;
    }
};