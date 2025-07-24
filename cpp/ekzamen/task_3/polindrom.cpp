#include <fstream>
#include <string>

using namespace std;

struct Node {
    int coefficient;
    int power;
    Node* next = nullptr;
};

bool is_prime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2)
        if (num % i == 0) return false;
    return true;
}

bool is_palindrome(int num) {
    string s = to_string(num);
    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] != s[s.length() - 1 - i]) return false;
    }
    return true;
}

bool is_prime_and_palindrome(int num) {
    return is_palindrome(num) && is_prime(num);
}

void print_polynome(Node* top, ofstream& out) {
    if (top == nullptr) {
        out << "There is no data!" << endl;
        return;
    }

    Node* node = top;
    bool first = true;
    while (node) {
        if (node->coefficient != 0) {
            if (!first && node->coefficient > 0) out << "+";
            out << node->coefficient << "x^" << node->power;
            first = false;
        }
        node = node->next;
    }
    out << endl;
}

void push(Node*& top, int coefficient, int power) {
    if (top == nullptr) {
        top = new Node{coefficient, power, nullptr};
        return;
    }
    Node* temp = top;
    while (true) {
        if (temp->power == power) {
            temp->coefficient += coefficient;
            return;
        }
        if (temp->next == nullptr) break;
        temp = temp->next;
    }
    temp->next = new Node{coefficient, power, nullptr};
}

void create_polynome(Node*& polynome, ifstream& in) {
    int n;
    in >> n;
    int coefficient, power;
    for (int i = 0; i < n; i++) {
        in >> coefficient >> power;
        push(polynome, coefficient, power);
    }
}

bool is_all_elements_prime_and_palindrome(Node* top) {
    while (top) {
        if (!is_prime_and_palindrome(top->coefficient))
            return false;
        top = top->next;
    }
    return true;
}

bool has_prime_and_palindrome(Node* top) {
    while (top) {
        if (is_prime_and_palindrome(top->coefficient))
            return true;
        top = top->next;
    }
    return false;
}

Node* subtract_polynomes(Node* p1, Node* p2) {
    Node* result = nullptr;
    Node* temp = p1;
    while (temp) {
        push(result, temp->coefficient, temp->power);
        temp = temp->next;
    }
    temp = p2;
    while (temp) {
        push(result, -temp->coefficient, temp->power);
        temp = temp->next;
    }
    return result;
}

Node* mult_polynomes(Node* p1, Node* p2) {
    Node* result = nullptr;
    Node* temp = p1;
    while (temp) {
        Node* temp2 = p2;
        while (temp2) {
            push(result, temp->coefficient * temp2->coefficient, temp->power + temp2->power);
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    return result;
}

int main() {
    ifstream in1("p1.txt");
    ifstream in2("p2.txt");
    ofstream out("data.out");

    Node* P1 = nullptr;
    Node* P2 = nullptr;
    Node* P3 = nullptr;

    create_polynome(P1, in1);
    create_polynome(P2, in2);

    in1.close();
    in2.close();

    print_polynome(P1, out);
    print_polynome(P2, out);

    if (is_all_elements_prime_and_palindrome(P1) && !has_prime_and_palindrome(P2)) {
        P3 = mult_polynomes(P1, P2);
    } else {
        P3 = subtract_polynomes(P1, P2);
    }

    print_polynome(P3, out);

    out.close();
    return 0;
}