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
//�����߳̽����ӡ1һ����ӡ������һ����ӡż��
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
				cout <<"�߳�һ"<< this_thread::get_id() << ":" << base << endl;
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
				cond.wait(lock, [&flag]() {return flag; });//�ڻ�ȡ����˲������
				cout <<"�̶߳�" << this_thread::get_id() << ":" << base << endl;
				++base;
				flag = !flag;
				cond.notify_one();
			}
		});
	t2.join();
	t1.join();
	return 0;

		
	
	

}