#include <iostream>
#include <random>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

void create_part_array(char* arr, unsigned long long size) {
	random_device r1;	//RNG using underlying sources such as hardware-events to generate a number r1 
	mt19937 gen(r1());	//RNG with a period of 2^19937 - 1 creating a random number between 0 and 2^32 -1 based on r1
	uniform_int_distribution<> dis(-128, 127);	//used to convert the random number created by mt19937 to a one Byte value (char)
	//initializing RAM with values
	for (unsigned long long i = 0; i < size; i++) {
		arr[i] = dis(gen);
	}
}

void create_array(unsigned long long size, int nr_threads) {
	char* arr = new char[size];
	unsigned int start = 0;
	unsigned long long part_size = size / nr_threads;
	thread* t = new std::thread[nr_threads]; // Array to store the thread objects

	for (int i = 0; i < nr_threads; i++) {
		start = i * part_size;
		t[i] = thread(create_part_array, &arr[start], part_size);
	}
	for (int i = 0; i < nr_threads; i++) {
		t[i].join();
	}

	delete[] t;
}

void spawnThreads() {
	//using cout with << -> not thread safe
	thread* t = new thread[10];
	for (int i = 0; i < 10; i++) {
		t[i] = thread([i]() {cout << "I'm thread " << i << endl; });
	}
	for (int i = 0; i < 10; i++) {
		t[i].join();
	}
	delete[] t;

	cout << endl << endl;

	//using printf -> thread safe
	thread* t2 = new thread[10];
	for (int i = 0; i < 10; i++) {
		t2[i] = thread([i]() {printf("I'm thread %d\n", i); });
	}
	for (int i = 0; i < 10; i++) {
		t2[i].join();
	}
	delete[] t2;
}

void incrementData(int* sharedData, mutex& mtx, string thread_name) {
	for (int i = 0; i < 10000; i++) {
		//printing output using cout in a thread-safe way
		mtx.lock();
		cout << thread_name << " incrementing data." << endl;
		(*sharedData)++;
		mtx.unlock();
	}

}

void mutexes() {
	int sharedData = 0;
	mutex m;

	//std::ref() necessary to pass by reference
	thread t1(incrementData, &sharedData, ref(m), "thread 1");
	thread t2(incrementData, &sharedData, ref(m), "thread 2");
	thread t3(incrementData, &sharedData, ref(m), "thread 3");


	t1.join();
	t2.join();
	t3.join();

	cout << "Final value of shared data: " << sharedData << endl;
}

int main() {
	//create_array(pow(2, 25), 16);
	spawnThreads();

	mutexes();
	return 0;
}

