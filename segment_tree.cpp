/*
In order to use segtree class defined above, you will need to create a datatype(a struct most likely), which will implement the function merge(). It can also additionally implement split, if you need to define the split operation.
A sample is shown as "struct segtree_node" in the code above.

The segtree has to be instantiated with this defined data type. For example,as
segtree<segtree_node> s;

You have to first call the init function of the class, which will take
  int n=number of elements in your array,
  node[] = your inital array,
  identity = an element such that merge(y,identity) = merge(identity,y) = y for all y's.

To call the query function, you will need to give 0-based index of the range, range should be *non empty*.

To use the update function, you will need to supply the update_single_subtree function as a template argument.

There are two versions of update and query functions: one for a single leaf, and one for a range.

To use the binary search function, you will need to define "operator<", so that an ordering gets defined.
*/



#include"assert.h"
struct segtree_node{/*{{{*/
public:
  void merge(segtree_node&, segtree_node&){}
  void split(segtree_node&, segtree_node&){}
};/*}}}*/
template<class node>
class segtree{/*{{{*/
	template<bool b>class param{};
	inline void spltdwn(int idx,param<true>){splt(idx);}
	inline void splt(int idx){/*{{{*/
		idx>>=1;
		if(idx>0)splt(idx);
		tree[idx].split(tree[idx<<1],tree[(idx<<1)|1]);
	}/*}}}*/
	inline void spltdwn(int,param<false>){};
	inline void split(node& a, node& b, node& c, param<true> ){return a.split(b,c);}
	inline void split(node&, node&, node&, param<false>){}
	template<typename t,void (t::*)(t&,t&)> class T{};
	template<typename t> static char test(T<t,&t::split>*){return 0;}
	template<typename t> static long double test(...){return 0;}
	int u,v;
	node query(int root, int left_range, int right_range){/*{{{*/
		if(u<=left_range && right_range<=v)
			return tree[root];
		int mid = (left_range + right_range)>>1,
			l = root<<1,
			r = l|1;
		if(has_split)split(tree[root],tree[l],tree[r],param<has_split>());
		node res;
		if(u>=mid)res=query(r,mid,right_range);
		else if(v<=mid)res=query(l,left_range,mid);
		else{
			node n1 = query(l,left_range,mid),
				 n2 = query(r,mid,right_range);
			res.merge(n1,n2);
		}
                if(has_split) tree[root].merge(tree[l],tree[r]);
		return res;
	}/*}}}*/
 	template<void(*fn)(node&)>
	void local_update(int root, int left_range,int right_range){/*{{{*/
		if(u<=left_range && right_range<=v){
			return fn(tree[root]);
		}
		int mid = (left_range + right_range)>>1,
			l = root<<1,
			r = l|1;
		if(has_split)split(tree[root],tree[l],tree[r],param<has_split>());
		if(v>mid)local_update<fn>(r,mid,right_range);
		if(u<mid)local_update<fn>(l,left_range,mid);
		tree[root].merge(tree[l],tree[r]);
	}/*}}}*/
	void mrgup(int idx){/*{{{*/
		idx>>=1;
		while(idx>0)
			tree[idx].merge(tree[idx<<1],tree[(idx<<1)|1]),
			idx>>=1;
	}/*}}}*/
public:
	static bool const has_split = (sizeof(test<node>(0))==sizeof(char));
	int N;
	int leftmost_leaf, rightmost_leaf;
	node* tree;
	node identity;
	segtree(){ tree=0; }
	~segtree(){
                if(tree) delete[] tree;
	}
	void init(int n, const node a[], const node& identity){/*{{{*/
                if(tree) delete[] tree;
		this->identity = identity;
		N=0;
		while((1<<N)<n)N++;
		leftmost_leaf = 1<<N;
		rightmost_leaf = leftmost_leaf<<1;
		tree = new node[rightmost_leaf];
		for(int i=0;i<n;i++)
			tree[i+leftmost_leaf] = a[i];
		for(int i=n+leftmost_leaf;i<rightmost_leaf;i++)
			tree[i]=identity;
		for(int i=leftmost_leaf-1;i;i--)
			tree[i].merge(tree[i<<1],tree[(i<<1)|1]);
	}/*}}}*/
	node query(int u, int v){//[u,v]/*{{{*/
		this->u=u+leftmost_leaf;
		this->v=v+leftmost_leaf+1;
		return query(1,leftmost_leaf,rightmost_leaf);
	}/*}}}*/
	node query(int u){//faster version of query(u,u)/*{{{*/
		//indexing starts from 0
		u+=leftmost_leaf;
		spltdwn(u,param<has_split>());
		return tree[u];
	}/*}}}*/
	template<void(*fn)(node&)>
	void update(int u, int v){/*{{{*/
		//0-indexed
		this->u=u+leftmost_leaf;
		this->v=v+leftmost_leaf+1;
		return local_update<fn>(1,leftmost_leaf,rightmost_leaf);
	}/*}}}*/
	template<void(*fn)(node&)>
	void update(int u){//faster version of update(u,u)/*{{{*/
		//indexing starts from 0
		u+=leftmost_leaf;
		spltdwn(u,param<has_split>());
		fn(tree[u]);
		mrgup(u);
	}/*}}}*/
	void split_down(int leaf_idx){/*{{{*/
		spltdwn(leaf_idx+leftmost_leaf,param<has_split>());
	}/*}}}*/
	void merge_up(int leaf_idx){/*{{{*/
		mrgup(leaf_idx+leftmost_leaf);
	}/*}}}*/
	bool is_leaf(int tree_idx){return tree_idx>=leftmost_leaf;}
	int binary_search(node k){/*{{{*/
	//search the last place i, such that merge( everyting to the left of i(including i) ) compares less than k
        int root = 1;
        node n=identity;
		//identity satisfies merge(identity,y) = merge(y,identity) = y for all y.
		assert(!(k<identity));
        while(!is_leaf(root)){
                int left_child = root<<1,
					right_child = left_child|1;
                if(has_split)
					split(tree[root],tree[left_child],tree[right_child],param<has_split>());
                node m;
                m.merge(n,tree[left_child]);
                if(m<k){//go to right side
                        n=m;
                        root=right_child;
                }else root=left_child;
        }
        node m;
        m.merge(n,tree[root]);
		mrgup(root);
        if(m<k)return root-leftmost_leaf;
        else return root-1-leftmost_leaf;
	}/*}}}*/
};/*}}}*/
int main(){

}
