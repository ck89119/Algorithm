#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0xc0
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lowbit(x) x & (-x)
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

class FileSystem {
 public:
  FileSystem() {
    root = new Node(1);
  }
  
  vector<string> ls(string path) {
    Node *cur_dir = root;
    for (auto dir_name: split(path))
      cur_dir = cur_dir->dir[dir_name];
    return cur_dir->List();
  }

  void mkdir(string path) {
    Node *cur_dir = root;
    for (auto dir_name: split(path)) {
      if (!cur_dir->HasDir(dir_name))
        cur_dir->AddDir(dir_name);
      cur_dir = cur_dir->dir[dir_name];
    }
  }

  void addContentToFile(string filePath, string content) {
    Node *cur_dir = root;
    auto dir_names = split(filePath);
    for (int i = 0; i < dir_names.size() - 1; ++i) {
      auto dir_name = dir_names[i];
      if (!cur_dir->HasDir(dir_name))
        cur_dir->AddDir(dir_name);
      cur_dir = cur_dir->dir[dir_name];
    }
    string file_name = dir_names[dir_names.size()-1];
    if (!cur_dir->HasDir(file_name))
      cur_dir->AddFile(file_name);
    Node *file_node = cur_dir->dir[file_name];
    file_node->AddContent(content);
  }

  string readContentFromFile(string filePath) {
    Node *cur_dir = root;
    auto dir_names = split(filePath);
    for (int i = 0; i < dir_names.size() - 1; ++i) {
      auto dir_name = dir_names[i];
      if (!cur_dir->HasDir(dir_name))
        cur_dir->AddDir(dir_name);
      cur_dir = cur_dir->dir[dir_name];
    }
    string file_name = dir_names[dir_names.size()-1];
    return cur_dir->dir[file_name]->GetContent(); 
  }

  vector<string> split(string path) {
    vector<string> v;
    if (path == "/") return v;

    int l = 0;
    for (int r = 1; r < path.size(); ++r)
      if (path[r] == '/') {
        v.push_back(path.substr(l+1, r-l-1));
        l = r;
      }
    v.push_back(path.substr(l+1));
    return v;
  }

 private:
  struct Node {
    // 1: dir; 2: file
    int type;
    string content;
    map<string, Node*> dir;

    Node(int type) {
      this->type = type;
    }

    Node(int type, string name) {
      this->type = type;
      this->dir[name] = this;
    }
    
    void AddFile(string file_name) {
      Node *node = new Node(2, file_name);
      dir[file_name] = node;
    }
    
    void AddDir(string dir_name) {
      Node *node = new Node(1);
      dir[dir_name] = node;
    } 

    bool HasDir(string dir_name) {
      return dir.find(dir_name) != dir.end();
    }

    void AddContent(const string &content) {
      this->content += content;
    }

    string GetContent() {
      return content;
    }

    vector<string> List() {
      vector<string> list;
      for (auto p: dir)
        list.push_back(p.first);
      return list;
    }
  };

  Node *root;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * vector<string> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * string param_4 = obj.readContentFromFile(filePath);
 */

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  FileSystem *obj = new FileSystem();
  dump("FileSystem");
  vector<string> param_1 = obj->ls("/");
  dump("ls");
  obj->mkdir("/a/b/c");
  dump("mkdir");
  obj->addContentToFile("/a/b/c/d", "hello");
  dump("addContentToFile");
  string param_4 = obj->readContentFromFile("/a/b/c/d");
  dump("readContentFromFile");
  cout << param_4 << endl;
  return 0;
}
