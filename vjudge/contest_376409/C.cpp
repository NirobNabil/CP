#include <bits/stdc++.h>
using namespace std;
#define umap unordered_map<int, node >
int nums[100100];
int BLOCK_SIZE, answers[100500];
int cnt[100100];

struct node{
	int val;
	deque<int> indices;
};
unordered_map<int, node> mods(100000);
struct node t1, t2;

struct ans_cmp {
    bool operator() (const int& x, const int& y) const {
        // if(mods.find(x) == mods.end()) return 0;
        if(mods.find(x) != mods.end()) t1 = mods[x]; else return 1; 
        if(mods.find(y) != mods.end()) t2 = mods[y]; else return 0;
        // printf("%d %d v %d %d i %d %d\n", x, y, t1.val, t2.val, *t1.indices.begin(), *t2.indices.begin());
        if(t1.val == t2.val){
            if(t1.indices.front() == t2.indices.front()) return 0;
            else return 1;
        }
        else return t1.val < t2.val;
    }
};
unordered_map<int, int> current_answers;

inline bool mo_cmp(const pair< pair<int, int>, int> &x, const pair< pair<int, int>, int> &y){
    int block_x = x.first.first / BLOCK_SIZE;
    int block_y = y.first.first / BLOCK_SIZE;
    if(block_x != block_y)
        return block_x < block_y;
    return x.first.second < y.first.second;
}

// inline printCurrent(set<int, ans_cmp> ans) {
// 	cout << ans.size() << "---> ";
// 	for(auto i : ans) cout << i << " ";
// 	cout << "\n";
// } 

inline void add(int a, int x){
	// current_answers.erase(mods[a].val);
	// printCurrent(current_answers);
	if(mods[a].indices.size()==0 || x > mods[a].indices.back()) mods[a].indices.push_back(x);
	else mods[a].indices.push_front(x);
	// mods[a].val = mods[a].indices.back() - mods[a].indices.front();
	// printf("add -> mods[%d].val = %d-%d = %d\n", a, mods[a].indices.back(), mods[a].indices.front(), mods[a].indices.back() - mods[a].indices.front());
	current_answers[mods[a].back() - mods[a].front()]++;
	// printCurrent(current_answers);
	// printf("\n");
	// if(*mods[current_answer].end() - *mods[current_answer].begin() < *mods[a].end() - *mods[a].begin()) {
	// 	current_answer = a;
	// }
}

inline void remove(int a, int x){
	current_answers.erase(mods[a].back() - mods[a].front());
	if(x == mods[a].indices.back()) mods[a].indices.pop_back();
	else mods[a].indices.pop_front();
	// printCurrent(current_answers);
	// if(mods[a].indices.size()) mods[a].val = mods[a].indices.back() - mods[a].indices.front();
    // else mods[a].val = 0;
	// printf("remove -> mods[%d].val = %d-%d = %d\n", a, mods[a].indices.back(), mods[a].indices.front(), mods[a].indices.back() - mods[a].indices.front());
	// current_answers.insert(a);
	// printCurrent(current_answers);
	// printf("\n");
	// if(*mods[current_answer].end() - *mods[current_answer].begin() < *mods[a].end() - *mods[a].begin()) {
	// 	current_answer = a;
	// }
}

pair< pair<int, int>, int> queries[10000];

int main(){
	long long int n, m;
	int k, l, r;
	scanf("%lld %lld %d", &n, &m, &k);
	BLOCK_SIZE = static_cast<int>(sqrt((n*n)/m));
	nums[0] = 0;
	// printf("%d ", nums[0]);
	for(int i=1; i<=n; i++) {
		scanf("%d", &nums[i]);
		nums[i] = (nums[i]+nums[i-1])%k; 
		// printf("%d ", nums[i]);
	}
	// printf("\n");
	for(int i=0; i<m; i++) {
		scanf("%d %d", &l, &r);
		queries[i] = make_pair(make_pair(l, r), i);
	}
	sort(queries, queries+m, mo_cmp);
	// for(int i=0; i<=k; i++) mods[i].val = 0;
	int mo_left = 0, mo_right = -1, left, right;
	for(int i=0; i<m; i++){
		left = queries[i].first.first-1;
		right = queries[i].first.second;
		// printf("%d %d\n", left, right);
		while(mo_right < right) {
            mo_right++;
            add(nums[mo_right], mo_right);
        }
        while(mo_right > right) {
            remove(nums[mo_right], mo_right);
            mo_right--;
        }

        while(mo_left < left) {
            remove(nums[mo_left], mo_left);
            mo_left++;
        }
        while(mo_left > left) {
            mo_left--;
            add(nums[mo_left], mo_left);
        }
        // printf("answers[%d] = mods[%d].val = %d\n" , queries[i].second, *current_answers.rbegin(), mods[*current_answers.rbegin()].val);
        answers[queries[i].second] = mods[*current_answers.rbegin()].val;
	} 
	for(int i=0; i<m; i++) {
		printf("%d\n", answers[i]);
	}
}