struct Node{
    Node* links[26] = {};
    bool flag = false;

    bool containsKey(char ch){
        return links[ch-'a'] != nullptr;
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch -'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class WordDictionary {
private:
    Node* root;

    bool dfs(string& word, int index, Node* node){
        if(index == word.size())
            return node->isEnd();

        char ch = word[index];

        if(ch == '.'){
            for(int i = 0; i<26;i++){
                if(node->links[i] && dfs(word, index+1, node->links[i]))
                    return true;
            }
            return false;
        }
        if(!node->containsKey(ch))
            return false;

        return dfs(word,index+1, node->get(ch));
    }
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;

        for(char ch : word){
            if(!node->containsKey(ch))
                node->put(ch, new Node());

            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
