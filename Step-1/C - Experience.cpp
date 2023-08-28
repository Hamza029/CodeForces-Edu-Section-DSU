#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define pi 2*acos(0.0)
#define readl(v,n) for(ll i=0;i<n;i++) {ll val; cin>>val; v.pb(val);}
#define srt(v) sort(v.begin(), v.end());
#define rsrt(v) sort(v.rbegin(), v.rend());
#define MIN(v) *min_element(v.begin(), v.end())
#define MAX(v) *max_element(v.begin(), v.end())
#define sz(x) ((ll) (x).size())
#define all(x) (x).begin(), (x).end()
#define vll vector <ll>
#define pll pair <ll, ll>
#define M 1000007
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"
#define inf 1000000000000000000
#define ninf -1000000000000000000
#define memo(x,val) memset(x,val,sizeof(x))

// PBDS

template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T> using multi_ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T> using r_ordered_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T> using r_multi_ordered_set = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// ordered_set<ll> s;
// s.order_of_key(k); --> number of items strictly smaller than k
// s.find_by_order(k); --> k-th item in set (0-indexing) (returns iterator)

// debugging

#define debx(x) cout << #x << " = " << (x) << endl
#define deb2(a,b) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<endl
#define deb3(a,b,c) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<endl
#define debv(v) cout<<#v<<" = "; for(auto x: v) {cout<<x<<", ";} cout<<endl;
#define debv2(v) for(int i=0; i<v.size(); i++) {cout<<#v<<"["<<i<<"] = "<<v[i]<<endl;}

template<typename... T>
void debm(T&&... args) {
    ((cout << args << ", "), ...);
    cout << endl;
}

/*
    ---- take notes here ----
    
*/

const ll N = 2e5+5;

ll parent[N];
ll Rank[N], cnt[N];

void make_set(ll n)
{
	for(ll i=1; i<=n; i++)
	{
		parent[i] = i;
		Rank[i] = 1;
		cnt[i] = 0;
	}
}

ll find_set(ll u) // no path compression
{
	if(parent[u] == u)
	{
		return u;
	}
	
	return find_set(parent[u]);
}

void Union(ll u, ll v)
{
	ll a = find_set(u);
	ll b = find_set(v);
	
	if(a == b)
	{
		return;
	}
	
	if(Rank[a] < Rank[b])
	{
		swap(a, b);
	}
	
	parent[b] = a;
	cnt[b] -= cnt[a];
	
	if(Rank[a] == Rank[b])
	{
		Rank[a]++;
	}
}

ll get_points(ll u)
{
	if(parent[u] == u)
	{
		return cnt[u];
	}
	
	return cnt[u] + get_points(parent[u]);
}

void solve()
{
    ll n,m; cin>>n>>m;
    
    make_set(n);
    
    while(m--)
    {
    	string s; cin>>s;
    	
    	if(s[0] == 'j')
    	{
    		ll u,v; cin>>u>>v;
    		Union(u, v);
    	}
    	else if(s[0] == 'a')
    	{
    		ll u, val; cin>>u>>val;
    		
    		ll p = find_set(u);
    		
    		cnt[p] += val;
    	}
    	else
    	{
    		ll u; cin>>u;
    		
    		cout<<get_points(u)<<endl;
    	}
    }
}

int main()
{
    FAST
    int t = 1;
    // cin >> t;
    while(t--)
    {
        #ifndef ONLINE_JUDGE
        cout<<endl;
        #endif
    
        solve();    
    }

    return 0;
}