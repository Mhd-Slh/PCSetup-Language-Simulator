//Mohamed Saleh

# include"Final_My_Language_C++.cpp"

int main()
{
	mouse a = 2, f = 3;
	keyboard b = 2.2, g = 3.3;
	headphone c = 'a', z = 'b';
	monitor e = "aaa", j = "bbb";
	charging d = true, i = false;
	
	mouse m1 = 5;
	mouse m2 = 3;
	mouse m3 = m1 + m2;
	display <"5 + 3 = "< m3<"\n"; // Outputs: 8
	
	keyboard k1 = 7.5;
	keyboard k2 = 2.4;
	keyboard k3 = k1 - k2;
	display <"7.5 + 2.4 = "< k3<"\n"; // Outputs: 5
	
	headphone h;
	display<"Enter a character: ";
	plugin > h; // Reads a character from input into 'h'
	display < h;
	
	monitor mo = "\nHello";
	display < mo; // Outputs: Hello
	
	charging c1 = true;
	charging c2 = false;
	charging c3 = c1 && c2;
	display <"\ntrue && false = "< c3; // Outputs: false

	
	return 0;
}

