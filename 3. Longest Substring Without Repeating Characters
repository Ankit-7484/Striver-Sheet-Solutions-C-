
class Solution {
public:
struct Hash_node
{
    int number;
    bool is;
    struct Hash_node * next;
};

struct Hash_node** Hash_table = new struct Hash_node*[10];

int Dup_Checker(int num)
{
    int k = num%10;
    if(Hash_table[k]==NULL)
    {
        struct Hash_node*ptr = new struct Hash_node;
        Hash_table[k] = ptr;
        Hash_table[k]->number = num;
        Hash_table[k]->is = true;
        Hash_table[k]->next = NULL;
        return 0;
    }
    else
    {
        struct Hash_node* temp = Hash_table[k];
        while(temp->next !=NULL)
        {
            if(temp->number == num)
            {
                if(temp->is == true)
                {
                    return 1;
                }
                else
                {
                    temp->is = true;
                    return 0;
                }
            }
            temp=temp->next;
        }
        if(temp->number == num)
        {
            if(temp->is == true)
            {
                return 1;
            }
            else
            {
                temp->is = true;
                return 0;
            }
            
        }
        struct Hash_node* ptr = new struct Hash_node;
        ptr->number = num;
        ptr->is = true;
        ptr->next = NULL;
        temp->next =ptr;
        return 0;
    }

}

int lengthOfLongestSubstring(string s) {

        if(s.length()==0)
        {
            return 0;
        }
        
        if(s.length()==1)
        {
            return 1;
        }
    
// Initializing the Hash table
for ( int i=0 ; i<10 ; i++)
{
    Hash_table[i] = NULL;
}

int sp= 0;
int ep = 0;
int s_sub = 0;
int mx_s_sub = 0;
for(int i = 0; i<s.length(); i++)
{
    if(!Dup_Checker((int)s[i]))
    {
        s_sub++;
        ep++;
    }
    else
    {
        if(mx_s_sub<s_sub)
        {
            mx_s_sub = s_sub;
        }

        while((int)s[sp] != (int)s[ep])
        {
            int num = (int)s[sp];
            int k = num%10;
            struct Hash_node* temp = Hash_table[k];
            while(temp!=NULL)
            {
                if(temp->number==num)
                {
                    temp->is = false;
                    s_sub--;
                    sp=sp+1;
                    break;
                }
                temp= temp->next;
            }
        }
        sp++;
        ep++;
    }
}


if(mx_s_sub<s_sub)
{
    mx_s_sub = s_sub;
}

return mx_s_sub;

}
};
