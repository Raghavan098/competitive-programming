struct suffix_automaton
{
    struct state
    {
        int len, link,l,r,f_len;
        map<char,int> to;

        state():len(0),link(-1),l(-1),r(-1){}
    };
    vector<state> st;
    int last,n;

    suffix_automaton():st(1),last(0){}

    void add(char c)
    {
        st.push_back(state());
        int cur=st.size()-1;
        st[cur].len=st[last].len+1;

        int p=last;
        for(; p+1 && !st[p].to[c]; p=st[p].link) st[p].to[c]=cur;
        if(p==-1) st[cur].link=0;
        else
        {
            int q=st[p].to[c];
            if(st[q].len==st[p].len+1) st[cur].link=q;
            else
            {
                st.push_back(st[q]);
                int cl=st.size()-1;
                st[cl].len=st[p].len+1;
                for(; p+1 && st[p].to[c]==q; p=st[p].link) st[p].to[c]=cl;
                st[cur].link=st[q].link=cl;
            }
        }
        last=cur;
    }

    void build(string s)
    {
        n=s.size();
        st.reserve(2*n);
        for(char it:s) add(it);
    }

};
