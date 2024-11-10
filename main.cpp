#include <string>
#include <iostream>

//////////////////////////////////////////////////////////////////////////////////////////////////
// ↓　基底クラス
//////////////////////////////////////////////////////////////////////////////////////////////////

class IShape {
public:

	IShape() {};
	virtual ~IShape() = default;

	virtual void Size() = 0;
	virtual void Draw() = 0;

protected:
	float area_ = 0;
};

//////////////////////////////////////////////////////////////////////////////////////////////////
// ↓　派生クラス
//////////////////////////////////////////////////////////////////////////////////////////////////

/// <summary>
/// 円
/// </summary>
class Circle : public IShape {
public:

	Circle(float radius) { radius_ = radius; };
	~Circle() override {};

	void Size() override {
		area_ = radius_ * radius_;
	};
	void Draw() override {
		std::cout << "面積 : " << area_ << std::endl;
	};

private:
	float radius_ = 0;
};

/// <summary>
/// 矩形
/// </summary>
class Rectangle : public IShape {
public:

	Rectangle(float width, float height) { width_ = width, height_ = height; };
	~Rectangle() override {};

	void Size() override {
		area_ = width_ * height_;
	};
	void Draw() override {
		std::cout << "面積 : " << area_ << std::endl;
	};

private:
	float width_ = 0;
	float height_ = 0;
};

//////////////////////////////////////////////////////////////////////////////////////////////////
// ↓　main処理
//////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
	
	bool isFinish_ = false;

	while (!isFinish_) {
		int input = 0;
		printf("CircleかRectangleを選んでください。終了するなら2を選んでください(Circle : 0, Rectangle : 1, 終了 : 2)\n");
		std::cin >> input;

		// 例外処理
		[&]() {
			while (input != 0 && input != 1 && input != 2) {
				printf("0か1か2を選んでください\n");
				std::cin >> input;
			}
			}();

		// 形の決定
		IShape* shape;

		if (input == 0) {			// 円形
			float radius = 0;
			printf("半径を入力してください\n");
			std::cin >> radius;
			shape = new Circle(radius);

		} else if (input == 1) {	// 矩形
			float width = 0;
			float height = 0;

			printf("横幅を入力してください\n");
			std::cin >> width;
			printf("縦幅を入力してください\n");
			std::cin >> height;
			shape = new Rectangle(width, height);

		} else {
			isFinish_ = true;
			continue;
		}

		// 計算と表示
		shape->Size();
		shape->Draw();

		// loop前処理
		delete shape;
		printf("\n");
	}

	return 0;
}