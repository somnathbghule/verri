#include <singletone.h>
#include <iostream>

CONFIG *CONFIG::config_ = NULL;

CONFIG::CONFIG() {
	DEBUG();
}
CONFIG::CONFIG(const CONFIG &config) {
	DEBUG();
}
CONFIG &CONFIG::operator=(const CONFIG &config) {
	DEBUG();
}
CONFIG *CONFIG::config() {
	if(!config_)
		config_ = new CONFIG();
	return config_;
}
