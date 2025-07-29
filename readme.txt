you could have certain error meesges when using string because of checked_string class. below is what it does .
It's a safer version of std::string: It inherits all the normal string features but adds extra checking.

It prevents out-of-bounds errors: When you try to access a character using [] (like my_string[5]), it secretly uses a safer method (at()) that checks if the position exists.

It tells you when it's being used: Each time you access a character with [], it prints a message to the error console saying "PPP::string::[]" so you can see when this happens.

Works for both regular and const strings: There are two versions - one for normal strings you can change, and one for strings you can't change.

 - you can comment out the section in PPP.h that includes it if you pay attention. but dont be afraid of the errors.

