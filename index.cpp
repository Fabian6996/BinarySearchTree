#include<iostream>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidSubTreeBST(root, LLONG_MIN, LLONG_MAX);
    }

private:
    bool isValidSubTreeBST(TreeNode* node, long long lowerVal, long long upperVal) {
        if (node == nullptr) {
            return true;
        }

        // Verificăm dacă valoarea curentă a nodului este în intervalul permis
        if (node->val <= lowerVal || node->val >= upperVal) {
            return false;
        }

        // Verificăm recursiv subarborile stâng și drept
        return isValidSubTreeBST(node->left, lowerVal, node->val) && isValidSubTreeBST(node->right, node->val, upperVal);
    }

public:
    static void deleteTree(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};
/**

            2
          /   \
        4       7
      /   \       \
    3       5       6


    BST:
    - radacina (cel mai de sus nod):
        - are o valoare cheie
        - orice nod in subarborele stang are o valoare cheie mai mica decat radacina (valoarea nod din subarborele stang < radacina)
        - orice nod in subarborele drept are o valoare cheie mai mare decat radacina (valoarea nod din subarbodere drept > radacina)
                9
              /   \
            7       8

    - subarbori (copaceii care se formeaza sub radacina):
        - exact aceleasi reguli se aplica si pt fiecare nod din subarborii stang si drept
        - fiecare subarbore este la randul sau BTS
                9
             /     \
            7       10
          /   \    /   \
        6      8  5     11

    - conditii:
        - valorile cheie ale nodurilor trebuie sa fie distincte, adica nu se pot repeta
    **/

int main() {
    // Exemplu de utilizare
    Solution obj;

    // Citirea valorilor de la tastatură
    int val1, val2, val3;
    cout << "Introdu valoarea pentru radacina: ";
    cin >> val1;
    cout << "Introdu valoarea pentru subarborele stang: ";
    cin >> val2;
    cout << "Introdu valoarea pentru subarborele drept: ";
    cin >> val3;

    // Construim un BST cu valorile citite
    TreeNode* root = new TreeNode(val1);
    root->left = new TreeNode(val2);
    root->right = new TreeNode(val3);

    // Verificăm dacă este un BST
    if (obj.isValidBST(root)) {
        cout << "Este un BST." << endl;
    } else {
        cout << "Nu este un BST." << endl;
    }

    // Eliberăm memoria alocată pentru arbore
    Solution::deleteTree(root);

    return 0;
}