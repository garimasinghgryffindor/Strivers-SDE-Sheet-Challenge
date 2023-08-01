class Kthlargest {
public:
    priority_queue<int>left;
    priority_queue<int, vector<int>, greater<int>> right;
    int K;
    Kthlargest(int k, vector<int> &arr) {
        K = k;
        for(int i=0 ; i<arr.size() ; i++) {
            if(right.size() < k) {
                right.push(arr[i]);
            } else {
                int tp = right.top();
                if(arr[i] > tp) {
                    right.push(arr[i]);
                } else {
                    left.push(arr[i]);
                }

                if(right.size() > k) {
                    int tp = right.top();
                    right.pop();
                    left.push(tp);
                } else if(right.size() < k) {
                    int tp = left.top();
                    left.pop();
                    right.push(tp);
                }
            }
        }
    }

    int add(int num) {
        if(right.size() < K) {
            right.push(num);
        } else {
            int tp = right.top();
            if(num > tp) {
                right.push(num);
            } else {
                left.push(num);
            }

            if(right.size() > K) {
                int tp = right.top();
                right.pop();
                left.push(tp);
            } else if(right.size() < K) {
                int tp = left.top();
                left.pop();
                right.push(tp);
            }
        }

        int res = right.top();
        return res;
    }

};
