 static const int __ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int init = [] {
    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());
    for (string str; getline(cin, str); cout << '\n') {
        if (str.find(',') == string::npos) {
            cout << str;
            continue;
        }
        stringstream ss(str); ss.ignore();
        int prev; ss >> prev; ss.ignore();
        cout << '[' << prev;
        for (int curr; ss >> curr; ss.ignore()) {
            cout << ',' << gcd(prev, curr) << ',' << curr;
            prev = curr;
        }
        cout << ']';
    }
    exit(0);
    return 0;
}();
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == NULL)return head;
        ListNode * temp = head->next,*prev = head;
        while(temp!=NULL){
            int k = gcd(prev->val,temp->val);
            ListNode * newnode = new ListNode(k);
            newnode->next = temp;
            prev->next = newnode;
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};