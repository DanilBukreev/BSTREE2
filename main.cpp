#include <iostream>
using namespace std;

struct Node {
  int key;
  Node *left;
  Node *right;
};

class BStree {
  Node *root;

 public:
  BStree() { root = nullptr; }
  void add_node(int key, Node *&root) {
    if (root == nullptr) {
      root = new Node;
      root->key = key;
      root->left = root->right = nullptr;
    }
    if (key < root->key) {
      if (root->left != nullptr)
        add_node(key, root->left);
      else {
        root->left = new Node;
        root->left->left = root->left->right = nullptr;
        root->left->key = key;
      }
    }
    if (key > root->key) {
      if (root->right != nullptr)
        add_node(key, root->right);
      else {
        root->right = new Node;
        root->right->left = root->right->right = nullptr;
        root->right->key = key;
      }
    }
  }
  void insert(int key) { add_node(key, root); }
  ~BStree() {}
};

void menu(BStree *&tree) {
  int c;
  string s;
  cout << " " << endl;
  cout << "1. Вывести дерево на экран" << endl;
  cout << "2. Вывести список узлов дерева" << endl;
  cout << "3. Добавить узел в дерево" << endl;
  cout << "4. Удалить узел из дерева" << endl;
  cout << "5. Сохранить дерево в файл" << endl;
  cout << "6. Загрузить дерево из файла" << endl;
  cout << "7. Проверить наличие узла" << endl;
  cout << "8. Завершить работу программы" << endl;
  do {
    cin >> c;
    switch (c) {
      case 8: {
        cout << "Вы хотите выйти из программы ? (y,N):" << endl;
        cin >> s;
        if (s == "yes" || s == "YES" || s == "Yes" || s == "Y" || s == "y")
          cout << "Всего доброго!" << endl;
        break;
      }
    }
  } while (s != "yes" && s != "YES" && s != "Yes" && s != "Y" && s != "y");
}
int main(int argc, char *argv[]) {
  BStree *tree = new BStree;
  for (int i = 1; i < argc; i++) {
    tree->insert(atoi(argv[i]));
  };
  menu(tree);
  delete tree;
}
