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
	virtual double Bill();
	double Savings(Sale& Other);
	bool operator<(Sale& Other) {
		return this->GetPrice() < Other.GetPrice();
	}
};

class DiscountSale : public Sale {
private:
	double Discount;

public:
	DiscountSale() {
		this->Discount = 0;
	}
	DiscountSale(double ThePrice, double theDiscount) {
		this->Discount = ThePrice * (1 - theDiscount);
	}

	double GetDiscount();
	void SetDiscount();
	double Bill();
	double Savings(DiscountSale& Other);

};

// 입력받은 퍼센트를 소수로 바꾸는 함수
double convertToNumber(const string& str) {
	string numStr;
	for (char ch : str) {
		if (ch != '%') {
			numStr += ch;
		}
	}

	double number = stod(numStr);
	return number / 100.0; // 변환된 숫자 값을 백분율로 표현하기 위해 100으로 나누기
}

int main() {
	int item1, item2;
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

	delete sale1;
	delete sale2;

	return 0;
}