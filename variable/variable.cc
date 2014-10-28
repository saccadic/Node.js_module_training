#include <iostream>
#include <node.h>
#include <v8.h>

#include <string.h>

using namespace std;
using namespace v8;

int n = 0;

class hoge{
public:
	int sum(int a, int b){
		return a + b;
	}
	void setname(string Str){
		s = Str;
	}
	string getname(){
		//string s = string(str);
		return s;
	}

	hoge(){
		str = (char *)malloc(100);
		cout << "Set" << endl;
	}
	~hoge(){
		free(str);
		cout << "Free" << endl;
	}
private:
	char *str;
	string	s;
};


Handle<Value> value_A(const Arguments& args) {
	HandleScope scope;
	n = args[0]->Int32Value();
	return scope.Close(v8::Int32::New(n));
}

Handle<Value> value_B(const Arguments& args) {
	HandleScope scope;
	return scope.Close(v8::Int32::New(n));
}

Handle<Value> class_A(const Arguments& args) {
	HandleScope scope;
	hoge huga;
	int n;

	n = huga.sum(args[0]->Int32Value(),args[1]->Int32Value());
	return scope.Close(v8::Int32::New(n));
}

Handle<Value> class_B(const Arguments& args) {
	HandleScope scope;
	hoge huga;
	string tmp,str;

	tmp = args[0]->a;

	huga.setname(tmp);

	str = huga.getname();
	return scope.Close(v8::Int32::New(n));
}

void init(Handle<Object> exports) {
	exports->Set(String::NewSymbol("value_A"), FunctionTemplate::New(value_A)->GetFunction());
	exports->Set(String::NewSymbol("value_B"), FunctionTemplate::New(value_B)->GetFunction());
	exports->Set(String::NewSymbol("sum"), FunctionTemplate::New(class_A)->GetFunction());
	exports->Set(String::NewSymbol("sum"), FunctionTemplate::New(class_A)->GetFunction());
}

NODE_MODULE(variable, init)