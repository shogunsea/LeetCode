class Solution 
{
public:
	/**
	* Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
	**/
	// Time Limit Exceeded
    char *strStr1(char *haystack, char *needle) 
	{ 
		char *p = haystack;
		char *q = needle;
		if (haystack == NULL && needle == NULL)
			return NULL;
		if (*needle == NULL)
			return haystack;
		
		while (*p != '\0')
		{
			if (*p == *q) {
				char *ret = p;
				while (*q != '\0' && *p != '\0' && *p == *q)
				{
					p ++;
					q ++;
				}
				if (*q == '\0')
					return ret;		
				q = needle;
				p = ret;
			}
			p ++;
		}
		return NULL;
        
    }
	
	/**
	** use p1Adv to control the loop times. if loop times > n-m+1, then end the function.
	**/
	char *strStr2(char *haystack, char *needle) 
	{ 
		if (!*needle) return haystack;
		char *p1 = (char*)haystack, *p2 = (char*)needle;
		char *p1Adv = (char*)haystack;
		while (*++p2)
			p1Adv++;
		while (*p1Adv) {
			char *p1Begin = p1;
			p2 = (char*)needle;
			while (*p1 && *p2 && *p1 == *p2) {
				p1++;
				p2++;
			}
			if (!*p2)
				return p1Begin;
			p1 = p1Begin + 1;
			p1Adv++;
		}
		return NULL;
	}
	
	/**
	* KMP algorithm
	**/
	char *strStr(char *haystack, char *needle) 
	{ 
		if (!*needle) return haystack;
		char *p1 = (char*)haystack, *p2 = (char*)needle;
		char *p1Adv = (char*)haystack;
		while (*++p2)
			p1Adv++;
		while (*p1Adv) {
			char *p1Begin = p1;
			p2 = (char*)needle;
			while (*p1 && *p2 && *p1 == *p2) {
				p1++;
				p2++;
			}
			if (!*p2)
				return p1Begin;
			p1 = p1Begin + 1;
			p1Adv++;
		}
		return NULL;
	}
};