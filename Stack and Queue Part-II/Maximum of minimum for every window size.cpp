#include <bits/stdc++.h> 
// brute force
vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int>res;
    
    for(int i=1 ; i<=n ; i++) {
        int ans = INT_MIN;
        deque<int>dq;
        for(int j=0 ; j<a.size() ; j++) {
            if(!dq.empty() && dq.front()==j-i) {
                dq.pop_front();
            }
            while(!dq.empty() && a[dq.back()] >= a[j]) {
                dq.pop_back();
            }
            dq.push_back(j);

            if(j+1 >= i) {
                ans = max(ans, a[dq.front()]);
            }
        }
        res.push_back(ans);
    }
    return res;
}


// optimal
// somewhat
vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int>res;
    vector<int>temp(a.begin(), a.end());
    int ele = *max_element(a.begin(), a.end());
    res.push_back(ele);

    for(int i=2 ; i<=n ; i++) {
        int ans = INT_MIN;
        for(int j=0 ; j<=a.size()-i ; j++) {
            if(temp[j] > temp[j+1]) {
                temp[j] = temp[j+1];
            }
            ans = max(ans, temp[j]);
        }
        res.push_back(ans);
    }
    return res;
}



// optimal
#include <bits/stdc++.h>
vector<int> maxMinWindow(vector<int> &a, int n) {
  stack<int> s;
  vector<int> leftSmall(n + 1, -1),
      rightSmall(n + 1, n); // it gives us length of every substring

  for (int i = 0; i < n; i++) {
    while (!s.empty() and a[s.top()] >= a[i])
      s.pop();
    if (!s.empty())
      leftSmall[i] = s.top();
    s.push(i);
  }

  while (!s.empty())
    s.pop();

  for (int i = n - 1; i >= 0; i--) {
    while (!s.empty() and a[s.top()] >= a[i])
      s.pop();
    if (!s.empty())
      rightSmall[i] = s.top();
    s.push(i);
  }

  vector<int> ans(n + 1, INT_MIN), res(n);
  for (int i = 0; i < n; i++) {
    int len =
        rightSmall[i] - leftSmall[i] - 1; // -1 because if len got beyond the
                                          // boundary then it will throws error
    ans[len] = max(ans[len], a[i]);
  }

  for (int i = n - 1; i >= 1; i--)
    ans[i] = max(ans[i], ans[i + 1]);

  for (int i = 1; i <= n; i++)
    res[i - 1] = ans[i];

  return res;
}
