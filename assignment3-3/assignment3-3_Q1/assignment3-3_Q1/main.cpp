#include <iostream>
#include <string>

using namespace std;

class Sale {
private:
    double Price;

public:
    Sale() {
        this->Price = 0;
    }
    Sale(double ThePrice) {
        this->Price = ThePrice;
    }

    double GetPrice() { return this->Price; }
    virtual double Bill() { return GetPrice(); } // ���� �״�� ��ȯ�ϴ� Bill() �Լ�
    // �ٸ� Sale ��ü���� ���� ���̸� ����Ͽ� ��ȯ�ϴ� Savings() �Լ�
    double Savings(Sale& Other) { return Other.GetPrice() - GetPrice(); }
    // Sale ��ü���� ������ ���ϴ� ������ �����ε�
    bool operator<(Sale& Other) { return GetPrice() < Other.GetPrice(); }
};

class DiscountSale : public Sale {
private:
    double Discount;

public:
    DiscountSale() {
        this->Discount = 0;
    }
    DiscountSale(double ThePrice, double theDiscount) : Sale(ThePrice) {
        this->Discount = theDiscount;
    }

    double GetDiscount() { return Discount; }
    void SetDiscount(double theDiscount) { Discount = theDiscount; }
    // ���ε� ������ ����Ͽ� ��ȯ�ϴ� Bill() �Լ�
    double Bill() { return GetPrice() * (1 - Discount); }
    // �ٸ� Sale ��ü���� ���ε� ���� ���̸� ����Ͽ� ��ȯ�ϴ� Savings() �Լ�
    double Savings(Sale& Other) { return Other.GetPrice() - Bill(); }
};

// �Է¹��� �ۼ�Ʈ�� �Ҽ��� �ٲٴ� �Լ�
double convertToNumber(const string& str) {
    string numStr;
    for (char ch : str) {
        if (ch != '%') {
            numStr += ch;
        }
    }

    double number = stod(numStr);
    return number / 100.0; // ��ȯ�� ���� ���� ������� ǥ���ϱ� ���� 100���� ������
}

int main() {
    double item1, item2;
    double percent;

    cout << "=======================================" << endl;
    cout << "Price Compare Program" << endl;
    cout << "=======================================" << endl;
    cout << "Insert item1 price: $";
    cin >> item1;
    cout << "Insert item2 price: $";
    cin >> item2;

    Sale* sale1 = new Sale(item1);
    Sale* sale2 = new Sale(item2);

    cout << endl << "---------------------------------------" << endl;
    cout << "Insert discount percent: ";
    string input;
    cin >> input;
    percent = convertToNumber(input);
    cout << endl << "---------------------------------------" << endl;

    DiscountSale* discount = new DiscountSale(item1, percent);

    cout << "Item1 price: $" << sale1->GetPrice() << endl;
    cout << "Item2 price: $" << sale2->GetPrice() << endl;
    cout << "Item1 bill after discount: $" << discount->Bill() << endl;
    cout << "Item1 savings compared to Item2: $" << discount->Savings(*sale2) << endl;

    delete sale1;
    delete sale2;
    delete discount;

    return 0;
}
