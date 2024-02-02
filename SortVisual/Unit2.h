//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class Buble : public TThread
{
private:
 void __fastcall Buble::b_sort();
protected:
	void __fastcall Execute();
public:
	__fastcall Buble(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
