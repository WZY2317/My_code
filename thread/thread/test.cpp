#include<iostream>
#include<thread>
#include<vector>
#include<condition_variable>
#include<mutex>
using namespace std;

void Func(vector<int>& v, int n, int base, mutex& mtx)
{
	try
	{
		for (int i = 0; i < n; i++)
		{
			unique_lock<mutex> lock(mtx);
			cout << _getpid() << ":" << base + i << endl;
			v.push_back(base + i);

		}
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
}
//int main()
//{
//	thread t1, t2;
//	vector<int> v;
//	try
//	{
//		t1 = thread(Func, ref(v), 100, 100, ref(mtx));
//		t2 = thread(Func, ref(v), 150, 100, ref(mtx));
//	}
//	catch (const std::exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	t1.join();
//	t2.join();
//
// }
//两个线程交替打印1一个打印奇数，一个打印偶数
int main()
{
	condition_variable cond;
	mutex mtx;
	int base = 1;
	int n = 100;
	bool flag = false;
	thread t1([n, &base, &mtx,&cond,&flag]
		{
			while (base < n)
			{
				unique_lock<mutex> lock(mtx);
				cond.wait(lock, [&flag]() {return !flag; });
				cout <<"线程一"<< this_thread::get_id() << ":" << base << endl;
				++base;
				flag = !flag;
				cond.notify_one();
			}
		}
	);
	thread t2([n, &base, &mtx,&cond,&flag]
		{
			while (base < n)
			{
				unique_lock<mutex> lock(mtx);
				cond.wait(lock, [&flag]() {return flag; });//在获取锁的瞬间会解锁
				cout <<"线程二" << this_thread::get_id() << ":" << base << endl;
				++base;
				flag = !flag;
				cond.notify_one();
			}
		});
	t2.join();
	t1.join();
	return 0;

		
	
	

}