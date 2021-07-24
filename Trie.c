struct TrieNode {
    char cur;
    int exist;
    int visited;
    struct TrieNode **subTrie;
};

int find_word (struct TrieNode *h, char* word) {
    while(*word != '\0') {
        h = h->subTrie[*word - 'a'];
        word++;
    }
    
    return h->exist;
}

void insert(struct TrieNode *h, char* word) {
    while(*word != '\0') {
        if(h->subTrie == NULL) {
            h->subTrie = (struct subTrie**) malloc(sizeof(struct subTrie*) * 26);
        }
        
        if(h->subTrie[*word-'a'] == NULL) {
            h->subTrie[*word-'a'] = (struct subTrie*)malloc(sizeof(struct subTrie));
            h->subTrie[*word - 'a']->cur = *word;
            h->subTrie[*word - 'a']->exist = 0;
            h->subTrie[*word - 'a']->visited = 0;
        }
        
        h = h->subTrie[*word-'a'];
        word++;
    }
    h->exist = 1;
    return;
}
    
int search(struct TrieNode *h, char* word) {
    while(*word != '\0') {
        if(h->subTrie == NULL || h->subTrie[*h - 'a'] == NULL) {
            return 0;
        }
        
        h = h->subTrie[*h - 'a'];
    }
    
    return h->exist && 1-h->visited;
}
