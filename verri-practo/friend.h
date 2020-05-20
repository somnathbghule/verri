#ifndef friend_h
#define friend_h

class vfs {
	public:
		vfs();
		int numFs();
		void numFs(int num);
		void showVfs();
	
	private:
		int numFs_;
		friend void setNumFs(vfs &v, int numfs);

			
};

void setNumFs(vfs &v, int numfs);

#endif
