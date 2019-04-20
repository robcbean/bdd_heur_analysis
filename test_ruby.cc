typedef unsigned int uint32_t;



#include "mtrInt.h"
#include "cuddObj.hh"
#include "output.h"
#include "operations.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void timeOut()
{
  std::vector<BDD> output;
  Cudd mgr(0,0);
  print_output(547,"62_175.xml","malik_fanin\tNONE\t-1.0\t-1.0\t5761\t7.777777777777778\t175.0	185.0	2.0	54.0	65.05382386916237	54.0",mgr,output,false,NULL,true);
}


int main( int argc, char **argv )
{

  Cudd mgr(175,0);
  
    mgr.AutodynDisable();
  
  double nodes_before=0;
  BDD x[547];
  double t1,t2,t3,t4;
  double  desc_t1=0,desc_t2=0,desc_t3=0,desc_t4=0,desc_t5=0;
  double  sum_nodes=0;
  DdNode* poutput[2];
  DdNode* ptotal[1];
  std::string str_output;
  char buffer[100];
  std::string grown="";
  std::string symmetric =  "";
  std::string symmetric_after = "";
  double minTerms=0;

  

  //Timeout process control
  pid_t child_pid = fork();
  pid_t parent_pid = getpid();
  int status;
  if( child_pid != 0 )
  {
    sleep(43200);
    timeOut();
    kill(child_pid,SIGTERM);
    exit(0);
  }

  //Output nodes
  std::vector<BDD> output(2);
  std::vector<BDD> count_nodes_vector;
  std::vector<unsigned long> count_nodes;
  std::vector<unsigned long> count_id;

  for(unsigned int i=0; i<2;i++)
  {
    output[i] = mgr.bddOne();
  }


  //Variables

  x[2]=mgr.bddVar(163); //2

  x[1]=mgr.bddVar(161); //1

  x[4]=mgr.bddVar(160); //4

  x[9]=mgr.bddVar(156); //9

  x[8]=mgr.bddVar(154); //8

  x[11]=mgr.bddVar(153); //11

  x[17]=mgr.bddVar(148); //17

  x[16]=mgr.bddVar(146); //16

  x[19]=mgr.bddVar(145); //19

  x[25]=mgr.bddVar(140); //25

  x[24]=mgr.bddVar(138); //24

  x[27]=mgr.bddVar(137); //27

  x[33]=mgr.bddVar(132); //33

  x[32]=mgr.bddVar(130); //32

  x[35]=mgr.bddVar(129); //35

  x[41]=mgr.bddVar(124); //41

  x[40]=mgr.bddVar(122); //40

  x[43]=mgr.bddVar(121); //43

  x[49]=mgr.bddVar(116); //49

  x[48]=mgr.bddVar(115); //48

  x[0]=mgr.bddVar(9); //0

  x[55]=mgr.bddVar(110); //55

  x[54]=mgr.bddVar(108); //54

  x[57]=mgr.bddVar(107); //57

  x[63]=mgr.bddVar(102); //63

  x[62]=mgr.bddVar(100); //62

  x[65]=mgr.bddVar(99); //65

  x[71]=mgr.bddVar(58); //71

  x[70]=mgr.bddVar(55); //70

  x[74]=mgr.bddVar(56); //74

  x[75]=mgr.bddVar(54); //75

  x[81]=mgr.bddVar(90); //81

  x[80]=mgr.bddVar(88); //80

  x[83]=mgr.bddVar(87); //83

  x[89]=mgr.bddVar(53); //89

  x[88]=mgr.bddVar(49); //88

  x[92]=mgr.bddVar(51); //92

  x[94]=mgr.bddVar(48); //94

  x[93]=mgr.bddVar(50); //93

  x[122]=mgr.bddVar(82); //122

  x[121]=mgr.bddVar(80); //121

  x[124]=mgr.bddVar(79); //124

  x[130]=mgr.bddVar(74); //130

  x[129]=mgr.bddVar(72); //129

  x[132]=mgr.bddVar(71); //132

  x[138]=mgr.bddVar(22); //138

  x[137]=mgr.bddVar(11); //137

  x[141]=mgr.bddVar(20); //141

  x[143]=mgr.bddVar(18); //143

  x[145]=mgr.bddVar(16); //145

  x[147]=mgr.bddVar(14); //147

  x[149]=mgr.bddVar(12); //149

  x[142]=mgr.bddVar(19); //142

  x[144]=mgr.bddVar(17); //144

  x[146]=mgr.bddVar(15); //146

  x[148]=mgr.bddVar(13); //148

  x[150]=mgr.bddVar(10); //150

  x[156]=mgr.bddVar(62); //156

  x[155]=mgr.bddVar(60); //155

  x[158]=mgr.bddVar(59); //158

  x[169]=mgr.bddVar(174); //169

  x[171]=mgr.bddVar(172); //171

  x[173]=mgr.bddVar(170); //173

  x[175]=mgr.bddVar(168); //175

  x[177]=mgr.bddVar(166); //177

  x[179]=mgr.bddVar(164); //179

  x[3]=mgr.bddVar(162); //3

  x[10]=mgr.bddVar(155); //10

  x[18]=mgr.bddVar(147); //18

  x[26]=mgr.bddVar(139); //26

  x[34]=mgr.bddVar(131); //34

  x[42]=mgr.bddVar(123); //42

  x[50]=mgr.bddVar(114); //50

  x[56]=mgr.bddVar(109); //56

  x[64]=mgr.bddVar(101); //64

  x[72]=mgr.bddVar(57); //72

  x[82]=mgr.bddVar(89); //82

  x[90]=mgr.bddVar(52); //90

  x[123]=mgr.bddVar(81); //123

  x[131]=mgr.bddVar(73); //131

  x[139]=mgr.bddVar(21); //139

  x[157]=mgr.bddVar(61); //157

  x[6]=mgr.bddVar(159); //6

  x[5]=mgr.bddVar(158); //5

  x[21]=mgr.bddVar(144); //21

  x[20]=mgr.bddVar(142); //20

  x[23]=mgr.bddVar(141); //23

  x[37]=mgr.bddVar(128); //37

  x[36]=mgr.bddVar(126); //36

  x[39]=mgr.bddVar(125); //39

  x[52]=mgr.bddVar(113); //52

  x[51]=mgr.bddVar(112); //51

  x[67]=mgr.bddVar(98); //67

  x[66]=mgr.bddVar(96); //66

  x[69]=mgr.bddVar(95); //69

  x[85]=mgr.bddVar(86); //85

  x[84]=mgr.bddVar(84); //84

  x[87]=mgr.bddVar(83); //87

  x[126]=mgr.bddVar(78); //126

  x[125]=mgr.bddVar(76); //125

  x[128]=mgr.bddVar(75); //128

  x[152]=mgr.bddVar(66); //152

  x[151]=mgr.bddVar(64); //151

  x[154]=mgr.bddVar(63); //154

  x[170]=mgr.bddVar(173); //170

  x[174]=mgr.bddVar(169); //174

  x[178]=mgr.bddVar(165); //178

  x[7]=mgr.bddVar(157); //7

  x[22]=mgr.bddVar(143); //22

  x[38]=mgr.bddVar(127); //38

  x[53]=mgr.bddVar(111); //53

  x[68]=mgr.bddVar(97); //68

  x[86]=mgr.bddVar(85); //86

  x[127]=mgr.bddVar(77); //127

  x[153]=mgr.bddVar(65); //153

  x[15]=mgr.bddVar(149); //15

  x[168]=mgr.bddVar(0); //168

  x[172]=mgr.bddVar(171); //172

  x[29]=mgr.bddVar(136); //29

  x[28]=mgr.bddVar(134); //28

  x[31]=mgr.bddVar(133); //31

  x[30]=mgr.bddVar(135); //30

  x[59]=mgr.bddVar(106); //59

  x[58]=mgr.bddVar(104); //58

  x[61]=mgr.bddVar(103); //61

  x[60]=mgr.bddVar(105); //60

  x[96]=mgr.bddVar(47); //96

  x[95]=mgr.bddVar(24); //95

  x[120]=mgr.bddVar(46); //120

  x[98]=mgr.bddVar(45); //98

  x[100]=mgr.bddVar(43); //100

  x[102]=mgr.bddVar(41); //102

  x[104]=mgr.bddVar(39); //104

  x[106]=mgr.bddVar(37); //106

  x[108]=mgr.bddVar(35); //108

  x[110]=mgr.bddVar(33); //110

  x[112]=mgr.bddVar(31); //112

  x[114]=mgr.bddVar(29); //114

  x[116]=mgr.bddVar(27); //116

  x[118]=mgr.bddVar(25); //118

  x[99]=mgr.bddVar(44); //99

  x[101]=mgr.bddVar(42); //101

  x[103]=mgr.bddVar(40); //103

  x[105]=mgr.bddVar(38); //105

  x[107]=mgr.bddVar(36); //107

  x[109]=mgr.bddVar(34); //109

  x[111]=mgr.bddVar(32); //111

  x[113]=mgr.bddVar(30); //113

  x[115]=mgr.bddVar(28); //115

  x[117]=mgr.bddVar(26); //117

  x[119]=mgr.bddVar(23); //119

  x[160]=mgr.bddVar(8); //160

  x[159]=mgr.bddVar(1); //159

  x[162]=mgr.bddVar(7); //162

  x[164]=mgr.bddVar(5); //164

  x[166]=mgr.bddVar(3); //166

  x[163]=mgr.bddVar(6); //163

  x[167]=mgr.bddVar(2); //167

  x[165]=mgr.bddVar(4); //165

  x[176]=mgr.bddVar(167); //176

  x[47]=mgr.bddVar(117); //47

  x[13]=mgr.bddVar(152); //13

  x[12]=mgr.bddVar(150); //12

  x[14]=mgr.bddVar(151); //14

  x[77]=mgr.bddVar(94); //77

  x[76]=mgr.bddVar(92); //76

  x[79]=mgr.bddVar(91); //79

  x[78]=mgr.bddVar(93); //78

  x[45]=mgr.bddVar(120); //45

  x[44]=mgr.bddVar(118); //44

  x[46]=mgr.bddVar(119); //46

  x[134]=mgr.bddVar(70); //134

  x[133]=mgr.bddVar(68); //133

  x[136]=mgr.bddVar(67); //136

  x[135]=mgr.bddVar(69); //135


  //Outputs
	output[0]=mgr.bddOne();
	output[1]=mgr.bddOne();









  //Gates
  std::cerr<<"Generating bdd ..."<<std::endl;
  t1 = get_user_time();
  			
	std::cerr<<"processing gate 184..."<<std::endl;
	x[184] = (!x[2]|x[1]);// and (not o_1_1 or o_1) 
	count_nodes_vector.push_back(x[184]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(184);
	
	std::cerr<<"processing gate 186..."<<std::endl;
	x[186] = (!x[3]|x[1])&(!x[1]|x[3]);// and (not m_1_2 or o_1) and (not o_1 or m_1_2) 
	count_nodes_vector.push_back(x[186]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(186);
	
	std::cerr<<"processing gate 188..."<<std::endl;
	x[188] = (!x[4]|x[1])&(!x[1]|x[4]);// and (not m_1_3 or o_1) and (not o_1 or m_1_3) 
	count_nodes_vector.push_back(x[188]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(188);
	
	std::cerr<<"processing gate 183..."<<std::endl;
	x[183] = (!x[1]|x[0]);// and (not o_1 or R) 
	count_nodes_vector.push_back(x[183]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(183);
	std::cerr<<"processing gate 182..."<<std::endl;
	x[182] = x[184]&x[186]&x[188]&x[183];//
	count_nodes_vector.push_back(x[182]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(182);
	Cudd_RecursiveDeref(mgr.getManager(),x[184].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[186].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[188].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[183].getNode());
	std::cerr<<"Appending gate to output[0] x[182]"<<std::endl;
	output[0]=output[0] & x[182];
		
	std::cerr<<"processing gate 192..."<<std::endl;
	x[192] = (!x[6]|x[5]);// and (not o_2_1 or m_2) 
	count_nodes_vector.push_back(x[192]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(192);
	
	std::cerr<<"processing gate 194..."<<std::endl;
	x[194] = (!x[7]|x[5])&(!x[5]|x[7]);// and (not m_2_2 or m_2) and (not m_2 or m_2_2) 
	count_nodes_vector.push_back(x[194]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(194);
	
	std::cerr<<"processing gate 191..."<<std::endl;
	x[191] = (!x[5]|x[0])&(!x[0]|x[5]);// and (not m_2 or R) and (not R or m_2) 
	count_nodes_vector.push_back(x[191]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(191);
	std::cerr<<"processing gate 190..."<<std::endl;
	x[190] = x[192]&x[194]&x[191];//
	count_nodes_vector.push_back(x[190]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(190);
	Cudd_RecursiveDeref(mgr.getManager(),x[192].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[194].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[191].getNode());
	std::cerr<<"Appending gate to output[0] x[190]"<<std::endl;
	output[0]=output[0] & x[190];
		
	std::cerr<<"processing gate 198..."<<std::endl;
	x[198] = (!x[9]|x[8])&(!x[8]|x[9]);// and (not m_3_1 or m_3) and (not m_3 or m_3_1) 
	count_nodes_vector.push_back(x[198]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(198);
	
	std::cerr<<"processing gate 200..."<<std::endl;
	x[200] = (!x[10]|x[8])&(!x[8]|x[10]);// and (not m_3_2 or m_3) and (not m_3 or m_3_2) 
	count_nodes_vector.push_back(x[200]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(200);
	
	std::cerr<<"processing gate 202..."<<std::endl;
	x[202] = (!x[11]|x[8]);// and (not o_3_3 or m_3) 
	count_nodes_vector.push_back(x[202]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(202);
	
	std::cerr<<"processing gate 197..."<<std::endl;
	x[197] = (!x[8]|x[0])&(!x[0]|x[8]);// and (not m_3 or R) and (not R or m_3) 
	count_nodes_vector.push_back(x[197]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(197);
	std::cerr<<"processing gate 196..."<<std::endl;
	x[196] = x[198]&x[200]&x[202]&x[197];//
	count_nodes_vector.push_back(x[196]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(196);
	Cudd_RecursiveDeref(mgr.getManager(),x[198].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[200].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[202].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[197].getNode());
	std::cerr<<"Appending gate to output[0] x[196]"<<std::endl;
	output[0]=output[0] & x[196];
		
	std::cerr<<"processing gate 206..."<<std::endl;
	x[206] = (!x[13]|x[12])&(!x[12]|x[13]);// and (not m_4_1 or o_4) and (not o_4 or m_4_1) 
	count_nodes_vector.push_back(x[206]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(206);
	
	std::cerr<<"processing gate 208..."<<std::endl;
	x[208] = (!x[14]|x[12])&(!x[12]|x[14]);// and (not m_4_2 or o_4) and (not o_4 or m_4_2) 
	count_nodes_vector.push_back(x[208]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(208);
	
	std::cerr<<"processing gate 210..."<<std::endl;
	x[210] = (!x[15]|x[12]);// and (not o_4_3 or o_4) 
	count_nodes_vector.push_back(x[210]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(210);
	
	std::cerr<<"processing gate 205..."<<std::endl;
	x[205] = (!x[12]|x[0]);// and (not o_4 or R) 
	count_nodes_vector.push_back(x[205]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(205);
	std::cerr<<"processing gate 204..."<<std::endl;
	x[204] = x[206]&x[208]&x[210]&x[205];//
	count_nodes_vector.push_back(x[204]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(204);
	Cudd_RecursiveDeref(mgr.getManager(),x[206].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[208].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[210].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[205].getNode());
	std::cerr<<"Appending gate to output[0] x[204]"<<std::endl;
	output[0]=output[0] & x[204];
		
	std::cerr<<"processing gate 214..."<<std::endl;
	x[214] = (!x[17]|x[16]);// and (not o_5_1 or m_5) 
	count_nodes_vector.push_back(x[214]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(214);
	
	std::cerr<<"processing gate 216..."<<std::endl;
	x[216] = (!x[18]|x[16])&(!x[16]|x[18]);// and (not m_5_2 or m_5) and (not m_5 or m_5_2) 
	count_nodes_vector.push_back(x[216]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(216);
	
	std::cerr<<"processing gate 218..."<<std::endl;
	x[218] = (!x[19]|x[16])&(!x[16]|x[19]);// and (not m_5_3 or m_5) and (not m_5 or m_5_3) 
	count_nodes_vector.push_back(x[218]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(218);
	
	std::cerr<<"processing gate 213..."<<std::endl;
	x[213] = (!x[16]|x[0])&(!x[0]|x[16]);// and (not m_5 or R) and (not R or m_5) 
	count_nodes_vector.push_back(x[213]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(213);
	std::cerr<<"processing gate 212..."<<std::endl;
	x[212] = x[214]&x[216]&x[218]&x[213];//
	count_nodes_vector.push_back(x[212]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(212);
	Cudd_RecursiveDeref(mgr.getManager(),x[214].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[216].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[218].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[213].getNode());
	std::cerr<<"Appending gate to output[0] x[212]"<<std::endl;
	output[0]=output[0] & x[212];
		
	std::cerr<<"processing gate 222..."<<std::endl;
	x[222] = (!x[21]|x[20]);// and (not o_6_1 or o_6) 
	count_nodes_vector.push_back(x[222]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(222);
	
	std::cerr<<"processing gate 224..."<<std::endl;
	x[224] = (!x[22]|x[20]);// and (not o_6_2 or o_6) 
	count_nodes_vector.push_back(x[224]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(224);
	
	std::cerr<<"processing gate 226..."<<std::endl;
	x[226] = (!x[23]|x[20])&(!x[20]|x[23]);// and (not m_6_3 or o_6) and (not o_6 or m_6_3) 
	count_nodes_vector.push_back(x[226]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(226);
	
	std::cerr<<"processing gate 221..."<<std::endl;
	x[221] = (!x[20]|x[0]);// and (not o_6 or R) 
	count_nodes_vector.push_back(x[221]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(221);
	std::cerr<<"processing gate 220..."<<std::endl;
	x[220] = x[222]&x[224]&x[226]&x[221];//
	count_nodes_vector.push_back(x[220]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(220);
	Cudd_RecursiveDeref(mgr.getManager(),x[222].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[224].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[226].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[221].getNode());
	std::cerr<<"Appending gate to output[0] x[220]"<<std::endl;
	output[0]=output[0] & x[220];
		
	std::cerr<<"processing gate 230..."<<std::endl;
	x[230] = (!x[25]|x[24])&(!x[24]|x[25]);// and (not m_7_1 or o_7) and (not o_7 or m_7_1) 
	count_nodes_vector.push_back(x[230]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(230);
	
	std::cerr<<"processing gate 232..."<<std::endl;
	x[232] = (!x[26]|x[24])&(!x[24]|x[26]);// and (not m_7_2 or o_7) and (not o_7 or m_7_2) 
	count_nodes_vector.push_back(x[232]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(232);
	
	std::cerr<<"processing gate 234..."<<std::endl;
	x[234] = (!x[27]|x[24]);// and (not o_7_3 or o_7) 
	count_nodes_vector.push_back(x[234]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(234);
	
	std::cerr<<"processing gate 229..."<<std::endl;
	x[229] = (!x[24]|x[0]);// and (not o_7 or R) 
	count_nodes_vector.push_back(x[229]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(229);
	std::cerr<<"processing gate 228..."<<std::endl;
	x[228] = x[230]&x[232]&x[234]&x[229];//
	count_nodes_vector.push_back(x[228]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(228);
	Cudd_RecursiveDeref(mgr.getManager(),x[230].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[232].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[234].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[229].getNode());
	std::cerr<<"Appending gate to output[0] x[228]"<<std::endl;
	output[0]=output[0] & x[228];
		
	std::cerr<<"processing gate 238..."<<std::endl;
	x[238] = (!x[29]|x[28])&(!x[28]|x[29]);// and (not m_8_1 or o_8) and (not o_8 or m_8_1) 
	count_nodes_vector.push_back(x[238]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(238);
	
	std::cerr<<"processing gate 240..."<<std::endl;
	x[240] = (!x[30]|x[28]);// and (not o_8_2 or o_8) 
	count_nodes_vector.push_back(x[240]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(240);
	
	std::cerr<<"processing gate 242..."<<std::endl;
	x[242] = (!x[31]|x[28])&(!x[28]|x[31]);// and (not m_8_3 or o_8) and (not o_8 or m_8_3) 
	count_nodes_vector.push_back(x[242]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(242);
	
	std::cerr<<"processing gate 237..."<<std::endl;
	x[237] = (!x[28]|x[0]);// and (not o_8 or R) 
	count_nodes_vector.push_back(x[237]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(237);
	std::cerr<<"processing gate 236..."<<std::endl;
	x[236] = x[238]&x[240]&x[242]&x[237];//
	count_nodes_vector.push_back(x[236]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(236);
	Cudd_RecursiveDeref(mgr.getManager(),x[238].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[240].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[242].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[237].getNode());
	std::cerr<<"Appending gate to output[0] x[236]"<<std::endl;
	output[0]=output[0] & x[236];
		
	std::cerr<<"processing gate 246..."<<std::endl;
	x[246] = (!x[33]|x[32]);// and (not o_9_1 or o_9) 
	count_nodes_vector.push_back(x[246]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(246);
	
	std::cerr<<"processing gate 248..."<<std::endl;
	x[248] = (!x[34]|x[32])&(!x[32]|x[34]);// and (not m_9_2 or o_9) and (not o_9 or m_9_2) 
	count_nodes_vector.push_back(x[248]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(248);
	
	std::cerr<<"processing gate 250..."<<std::endl;
	x[250] = (!x[35]|x[32])&(!x[32]|x[35]);// and (not m_9_3 or o_9) and (not o_9 or m_9_3) 
	count_nodes_vector.push_back(x[250]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(250);
	
	std::cerr<<"processing gate 245..."<<std::endl;
	x[245] = (!x[32]|x[0]);// and (not o_9 or R) 
	count_nodes_vector.push_back(x[245]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(245);
	std::cerr<<"processing gate 244..."<<std::endl;
	x[244] = x[246]&x[248]&x[250]&x[245];//
	count_nodes_vector.push_back(x[244]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(244);
	Cudd_RecursiveDeref(mgr.getManager(),x[246].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[248].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[250].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[245].getNode());
	std::cerr<<"Appending gate to output[0] x[244]"<<std::endl;
	output[0]=output[0] & x[244];
		
	std::cerr<<"processing gate 254..."<<std::endl;
	x[254] = (!x[37]|x[36])&(!x[36]|x[37]);// and (not m_10_1 or o_10) and (not o_10 or m_10_1) 
	count_nodes_vector.push_back(x[254]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(254);
	
	std::cerr<<"processing gate 256..."<<std::endl;
	x[256] = (!x[38]|x[36])&(!x[36]|x[38]);// and (not m_10_2 or o_10) and (not o_10 or m_10_2) 
	count_nodes_vector.push_back(x[256]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(256);
	
	std::cerr<<"processing gate 258..."<<std::endl;
	x[258] = (!x[39]|x[36]);// and (not o_10_3 or o_10) 
	count_nodes_vector.push_back(x[258]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(258);
	
	std::cerr<<"processing gate 253..."<<std::endl;
	x[253] = (!x[36]|x[0]);// and (not o_10 or R) 
	count_nodes_vector.push_back(x[253]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(253);
	std::cerr<<"processing gate 252..."<<std::endl;
	x[252] = x[254]&x[256]&x[258]&x[253];//
	count_nodes_vector.push_back(x[252]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(252);
	Cudd_RecursiveDeref(mgr.getManager(),x[254].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[256].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[258].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[253].getNode());
	std::cerr<<"Appending gate to output[0] x[252]"<<std::endl;
	output[0]=output[0] & x[252];
		
	std::cerr<<"processing gate 262..."<<std::endl;
	x[262] = (!x[41]|x[40]);// and (not o_11_1 or m_11) 
	count_nodes_vector.push_back(x[262]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(262);
	
	std::cerr<<"processing gate 264..."<<std::endl;
	x[264] = (!x[42]|x[40]);// and (not o_11_2 or m_11) 
	count_nodes_vector.push_back(x[264]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(264);
	
	std::cerr<<"processing gate 266..."<<std::endl;
	x[266] = (!x[43]|x[40]);// and (not o_11_3 or m_11) 
	count_nodes_vector.push_back(x[266]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(266);
	
	std::cerr<<"processing gate 261..."<<std::endl;
	x[261] = (!x[40]|x[0])&(!x[0]|x[40]);// and (not m_11 or R) and (not R or m_11) 
	count_nodes_vector.push_back(x[261]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(261);
	std::cerr<<"processing gate 260..."<<std::endl;
	x[260] = x[262]&x[264]&x[266]&x[261];//
	count_nodes_vector.push_back(x[260]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(260);
	Cudd_RecursiveDeref(mgr.getManager(),x[262].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[264].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[266].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[261].getNode());
	std::cerr<<"Appending gate to output[0] x[260]"<<std::endl;
	output[0]=output[0] & x[260];
		
	std::cerr<<"processing gate 270..."<<std::endl;
	x[270] = (!x[45]|x[44]);// and (not o_12_1 or m_12) 
	count_nodes_vector.push_back(x[270]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(270);
	
	std::cerr<<"processing gate 272..."<<std::endl;
	x[272] = (!x[46]|x[44]);// and (not o_12_2 or m_12) 
	count_nodes_vector.push_back(x[272]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(272);
	
	std::cerr<<"processing gate 274..."<<std::endl;
	x[274] = (!x[47]|x[44])&(!x[44]|x[47]);// and (not m_12_3 or m_12) and (not m_12 or m_12_3) 
	count_nodes_vector.push_back(x[274]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(274);
	
	std::cerr<<"processing gate 269..."<<std::endl;
	x[269] = (!x[44]|x[0])&(!x[0]|x[44]);// and (not m_12 or R) and (not R or m_12) 
	count_nodes_vector.push_back(x[269]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(269);
	std::cerr<<"processing gate 268..."<<std::endl;
	x[268] = x[270]&x[272]&x[274]&x[269];//
	count_nodes_vector.push_back(x[268]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(268);
	Cudd_RecursiveDeref(mgr.getManager(),x[270].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[272].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[274].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[269].getNode());
	std::cerr<<"Appending gate to output[0] x[268]"<<std::endl;
	output[0]=output[0] & x[268];
		
	std::cerr<<"processing gate 278..."<<std::endl;
	x[278] = (!x[49]|x[48])&(!x[48]|x[49]);// and (not m_13_1 or m_13) and (not m_13 or m_13_1) 
	count_nodes_vector.push_back(x[278]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(278);
	
	std::cerr<<"processing gate 280..."<<std::endl;
	x[280] = (!x[50]|x[48]);// and (not o_13_2 or m_13) 
	count_nodes_vector.push_back(x[280]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(280);
	
	std::cerr<<"processing gate 277..."<<std::endl;
	x[277] = (!x[48]|x[0])&(!x[0]|x[48]);// and (not m_13 or R) and (not R or m_13) 
	count_nodes_vector.push_back(x[277]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(277);
	std::cerr<<"processing gate 276..."<<std::endl;
	x[276] = x[278]&x[280]&x[277];//
	count_nodes_vector.push_back(x[276]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(276);
	Cudd_RecursiveDeref(mgr.getManager(),x[278].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[280].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[277].getNode());
	std::cerr<<"Appending gate to output[0] x[276]"<<std::endl;
	output[0]=output[0] & x[276];
		
	std::cerr<<"processing gate 284..."<<std::endl;
	x[284] = (!x[52]|x[51]);// and (not o_14_1 or m_14) 
	count_nodes_vector.push_back(x[284]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(284);
	
	std::cerr<<"processing gate 286..."<<std::endl;
	x[286] = (!x[53]|x[51]);// and (not o_14_2 or m_14) 
	count_nodes_vector.push_back(x[286]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(286);
	
	std::cerr<<"processing gate 283..."<<std::endl;
	x[283] = (!x[51]|x[0])&(!x[0]|x[51]);// and (not m_14 or R) and (not R or m_14) 
	count_nodes_vector.push_back(x[283]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(283);
	std::cerr<<"processing gate 282..."<<std::endl;
	x[282] = x[284]&x[286]&x[283];//
	count_nodes_vector.push_back(x[282]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(282);
	Cudd_RecursiveDeref(mgr.getManager(),x[284].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[286].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[283].getNode());
	std::cerr<<"Appending gate to output[0] x[282]"<<std::endl;
	output[0]=output[0] & x[282];
		
	std::cerr<<"processing gate 290..."<<std::endl;
	x[290] = (!x[55]|x[54])&(!x[54]|x[55]);// and (not m_15_1 or o_15) and (not o_15 or m_15_1) 
	count_nodes_vector.push_back(x[290]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(290);
	
	std::cerr<<"processing gate 292..."<<std::endl;
	x[292] = (!x[56]|x[54]);// and (not o_15_2 or o_15) 
	count_nodes_vector.push_back(x[292]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(292);
	
	std::cerr<<"processing gate 294..."<<std::endl;
	x[294] = (!x[57]|x[54]);// and (not o_15_3 or o_15) 
	count_nodes_vector.push_back(x[294]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(294);
	
	std::cerr<<"processing gate 289..."<<std::endl;
	x[289] = (!x[54]|x[0]);// and (not o_15 or R) 
	count_nodes_vector.push_back(x[289]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(289);
	std::cerr<<"processing gate 288..."<<std::endl;
	x[288] = x[290]&x[292]&x[294]&x[289];//
	count_nodes_vector.push_back(x[288]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(288);
	Cudd_RecursiveDeref(mgr.getManager(),x[290].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[292].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[294].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[289].getNode());
	std::cerr<<"Appending gate to output[0] x[288]"<<std::endl;
	output[0]=output[0] & x[288];
		
	std::cerr<<"processing gate 298..."<<std::endl;
	x[298] = (!x[59]|x[58])&(!x[58]|x[59]);// and (not m_16_1 or o_16) and (not o_16 or m_16_1) 
	count_nodes_vector.push_back(x[298]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(298);
	
	std::cerr<<"processing gate 300..."<<std::endl;
	x[300] = (!x[60]|x[58]);// and (not o_16_2 or o_16) 
	count_nodes_vector.push_back(x[300]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(300);
	
	std::cerr<<"processing gate 302..."<<std::endl;
	x[302] = (!x[61]|x[58])&(!x[58]|x[61]);// and (not m_16_3 or o_16) and (not o_16 or m_16_3) 
	count_nodes_vector.push_back(x[302]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(302);
	
	std::cerr<<"processing gate 297..."<<std::endl;
	x[297] = (!x[58]|x[0]);// and (not o_16 or R) 
	count_nodes_vector.push_back(x[297]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(297);
	std::cerr<<"processing gate 296..."<<std::endl;
	x[296] = x[298]&x[300]&x[302]&x[297];//
	count_nodes_vector.push_back(x[296]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(296);
	Cudd_RecursiveDeref(mgr.getManager(),x[298].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[300].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[302].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[297].getNode());
	std::cerr<<"Appending gate to output[0] x[296]"<<std::endl;
	output[0]=output[0] & x[296];
		
	std::cerr<<"processing gate 306..."<<std::endl;
	x[306] = (!x[63]|x[62])&(!x[62]|x[63]);// and (not m_17_1 or m_17) and (not m_17 or m_17_1) 
	count_nodes_vector.push_back(x[306]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(306);
	
	std::cerr<<"processing gate 308..."<<std::endl;
	x[308] = (!x[64]|x[62])&(!x[62]|x[64]);// and (not m_17_2 or m_17) and (not m_17 or m_17_2) 
	count_nodes_vector.push_back(x[308]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(308);
	
	std::cerr<<"processing gate 310..."<<std::endl;
	x[310] = (!x[65]|x[62])&(!x[62]|x[65]);// and (not m_17_3 or m_17) and (not m_17 or m_17_3) 
	count_nodes_vector.push_back(x[310]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(310);
	
	std::cerr<<"processing gate 305..."<<std::endl;
	x[305] = (!x[62]|x[0])&(!x[0]|x[62]);// and (not m_17 or R) and (not R or m_17) 
	count_nodes_vector.push_back(x[305]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(305);
	std::cerr<<"processing gate 304..."<<std::endl;
	x[304] = x[306]&x[308]&x[310]&x[305];//
	count_nodes_vector.push_back(x[304]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(304);
	Cudd_RecursiveDeref(mgr.getManager(),x[306].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[308].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[310].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[305].getNode());
	std::cerr<<"Appending gate to output[0] x[304]"<<std::endl;
	output[0]=output[0] & x[304];
		
	std::cerr<<"processing gate 314..."<<std::endl;
	x[314] = (!x[67]|x[66])&(!x[66]|x[67]);// and (not m_18_1 or o_18) and (not o_18 or m_18_1) 
	count_nodes_vector.push_back(x[314]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(314);
	
	std::cerr<<"processing gate 316..."<<std::endl;
	x[316] = (!x[68]|x[66])&(!x[66]|x[68]);// and (not m_18_2 or o_18) and (not o_18 or m_18_2) 
	count_nodes_vector.push_back(x[316]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(316);
	
	std::cerr<<"processing gate 318..."<<std::endl;
	x[318] = (!x[69]|x[66])&(!x[66]|x[69]);// and (not m_18_3 or o_18) and (not o_18 or m_18_3) 
	count_nodes_vector.push_back(x[318]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(318);
	
	std::cerr<<"processing gate 313..."<<std::endl;
	x[313] = (!x[66]|x[0]);// and (not o_18 or R) 
	count_nodes_vector.push_back(x[313]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(313);
	std::cerr<<"processing gate 312..."<<std::endl;
	x[312] = x[314]&x[316]&x[318]&x[313];//
	count_nodes_vector.push_back(x[312]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(312);
	Cudd_RecursiveDeref(mgr.getManager(),x[314].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[316].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[318].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[313].getNode());
	std::cerr<<"Appending gate to output[0] x[312]"<<std::endl;
	output[0]=output[0] & x[312];
		
	std::cerr<<"processing gate 322..."<<std::endl;
	x[322] = (!x[71]|x[70])&(!x[70]|x[71]);// and (not m_19_1 or m_19) and (not m_19 or m_19_1) 
	count_nodes_vector.push_back(x[322]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(322);
	
	std::cerr<<"processing gate 324..."<<std::endl;
	x[324] = (!x[72]|x[70]);// and (not o_19_2 or m_19) 
	count_nodes_vector.push_back(x[324]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(324);
		
	std::cerr<<"processing gate 328..."<<std::endl;
	x[328] = (!x[74]|x[70]);// and (not g_19_3_1 or m_19) 
	count_nodes_vector.push_back(x[328]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(328);
	
	std::cerr<<"processing gate 330..."<<std::endl;
	x[330] = (!x[75]|x[70]);// and (not g_19_3_2 or m_19) 
	count_nodes_vector.push_back(x[330]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(330);
	
	std::cerr<<"processing gate 327..."<<std::endl;
	x[327] = (!x[70]|(x[74]|x[75]))&(!x[74]|!x[75]);// and (not m_19 or (g_19_3_1 or g_19_3_2)) and (not g_19_3_1 or not g_19_3_2) 
	count_nodes_vector.push_back(x[327]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(327);
	std::cerr<<"processing gate 326..."<<std::endl;
	x[326] = x[328]&x[330]&x[327];//
	count_nodes_vector.push_back(x[326]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(326);
	Cudd_RecursiveDeref(mgr.getManager(),x[328].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[330].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[327].getNode());
	
	std::cerr<<"processing gate 321..."<<std::endl;
	x[321] = (!x[70]|x[0])&(!x[0]|x[70]);// and (not m_19 or R) and (not R or m_19) 
	count_nodes_vector.push_back(x[321]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(321);
	std::cerr<<"processing gate 320..."<<std::endl;
	x[320] = x[322]&x[324]&x[326]&x[321];//
	count_nodes_vector.push_back(x[320]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(320);
	Cudd_RecursiveDeref(mgr.getManager(),x[322].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[324].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[326].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[321].getNode());
	std::cerr<<"Appending gate to output[0] x[320]"<<std::endl;
	output[0]=output[0] & x[320];
		
	std::cerr<<"processing gate 334..."<<std::endl;
	x[334] = (!x[77]|x[76])&(!x[76]|x[77]);// and (not m_20_1 or o_20) and (not o_20 or m_20_1) 
	count_nodes_vector.push_back(x[334]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(334);
	
	std::cerr<<"processing gate 336..."<<std::endl;
	x[336] = (!x[78]|x[76])&(!x[76]|x[78]);// and (not m_20_2 or o_20) and (not o_20 or m_20_2) 
	count_nodes_vector.push_back(x[336]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(336);
	
	std::cerr<<"processing gate 338..."<<std::endl;
	x[338] = (!x[79]|x[76]);// and (not o_20_3 or o_20) 
	count_nodes_vector.push_back(x[338]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(338);
	
	std::cerr<<"processing gate 333..."<<std::endl;
	x[333] = (!x[76]|x[0]);// and (not o_20 or R) 
	count_nodes_vector.push_back(x[333]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(333);
	std::cerr<<"processing gate 332..."<<std::endl;
	x[332] = x[334]&x[336]&x[338]&x[333];//
	count_nodes_vector.push_back(x[332]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(332);
	Cudd_RecursiveDeref(mgr.getManager(),x[334].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[336].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[338].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[333].getNode());
	std::cerr<<"Appending gate to output[0] x[332]"<<std::endl;
	output[0]=output[0] & x[332];
		
	std::cerr<<"processing gate 342..."<<std::endl;
	x[342] = (!x[81]|x[80]);// and (not o_21_1 or o_21) 
	count_nodes_vector.push_back(x[342]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(342);
	
	std::cerr<<"processing gate 344..."<<std::endl;
	x[344] = (!x[82]|x[80])&(!x[80]|x[82]);// and (not m_21_2 or o_21) and (not o_21 or m_21_2) 
	count_nodes_vector.push_back(x[344]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(344);
	
	std::cerr<<"processing gate 346..."<<std::endl;
	x[346] = (!x[83]|x[80]);// and (not o_21_3 or o_21) 
	count_nodes_vector.push_back(x[346]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(346);
	
	std::cerr<<"processing gate 341..."<<std::endl;
	x[341] = (!x[80]|x[0]);// and (not o_21 or R) 
	count_nodes_vector.push_back(x[341]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(341);
	std::cerr<<"processing gate 340..."<<std::endl;
	x[340] = x[342]&x[344]&x[346]&x[341];//
	count_nodes_vector.push_back(x[340]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(340);
	Cudd_RecursiveDeref(mgr.getManager(),x[342].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[344].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[346].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[341].getNode());
	std::cerr<<"Appending gate to output[0] x[340]"<<std::endl;
	output[0]=output[0] & x[340];
		
	std::cerr<<"processing gate 350..."<<std::endl;
	x[350] = (!x[85]|x[84])&(!x[84]|x[85]);// and (not m_22_1 or o_22) and (not o_22 or m_22_1) 
	count_nodes_vector.push_back(x[350]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(350);
	
	std::cerr<<"processing gate 352..."<<std::endl;
	x[352] = (!x[86]|x[84]);// and (not o_22_2 or o_22) 
	count_nodes_vector.push_back(x[352]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(352);
	
	std::cerr<<"processing gate 354..."<<std::endl;
	x[354] = (!x[87]|x[84])&(!x[84]|x[87]);// and (not m_22_3 or o_22) and (not o_22 or m_22_3) 
	count_nodes_vector.push_back(x[354]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(354);
	
	std::cerr<<"processing gate 349..."<<std::endl;
	x[349] = (!x[84]|x[0]);// and (not o_22 or R) 
	count_nodes_vector.push_back(x[349]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(349);
	std::cerr<<"processing gate 348..."<<std::endl;
	x[348] = x[350]&x[352]&x[354]&x[349];//
	count_nodes_vector.push_back(x[348]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(348);
	Cudd_RecursiveDeref(mgr.getManager(),x[350].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[352].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[354].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[349].getNode());
	std::cerr<<"Appending gate to output[0] x[348]"<<std::endl;
	output[0]=output[0] & x[348];
		
	std::cerr<<"processing gate 358..."<<std::endl;
	x[358] = (!x[89]|x[88])&(!x[88]|x[89]);// and (not m_23_1 or m_23) and (not m_23 or m_23_1) 
	count_nodes_vector.push_back(x[358]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(358);
	
	std::cerr<<"processing gate 360..."<<std::endl;
	x[360] = (!x[90]|x[88])&(!x[88]|x[90]);// and (not m_23_2 or m_23) and (not m_23 or m_23_2) 
	count_nodes_vector.push_back(x[360]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(360);
		
	std::cerr<<"processing gate 364..."<<std::endl;
	x[364] = (!x[92]|x[88]);// and (not g_23_3_1 or m_23) 
	count_nodes_vector.push_back(x[364]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(364);
	
	std::cerr<<"processing gate 366..."<<std::endl;
	x[366] = (!x[93]|x[88]);// and (not g_23_3_2 or m_23) 
	count_nodes_vector.push_back(x[366]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(366);
	
	std::cerr<<"processing gate 368..."<<std::endl;
	x[368] = (!x[94]|x[88]);// and (not g_23_3_3 or m_23) 
	count_nodes_vector.push_back(x[368]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(368);
	
	std::cerr<<"processing gate 363..."<<std::endl;
	x[363] = (!x[88]|(x[92]|x[93]|x[94]))&(!x[92]|!x[93])&(!x[92]|!x[94])&(!x[93]|!x[94]);// and (not m_23 or (g_23_3_1 or g_23_3_2 or g_23_3_3)) and (not g_23_3_1 or not g_23_3_2) and (not g_23_3_1 or not g_23_3_3) and (not g_23_3_2 or not g_23_3_3) 
	count_nodes_vector.push_back(x[363]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(363);
	std::cerr<<"processing gate 362..."<<std::endl;
	x[362] = x[364]&x[366]&x[368]&x[363];//
	count_nodes_vector.push_back(x[362]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(362);
	Cudd_RecursiveDeref(mgr.getManager(),x[364].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[366].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[368].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[363].getNode());
	
	std::cerr<<"processing gate 357..."<<std::endl;
	x[357] = (!x[88]|x[0])&(!x[0]|x[88]);// and (not m_23 or R) and (not R or m_23) 
	count_nodes_vector.push_back(x[357]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(357);
	std::cerr<<"processing gate 356..."<<std::endl;
	x[356] = x[358]&x[360]&x[362]&x[357];//
	count_nodes_vector.push_back(x[356]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(356);
	Cudd_RecursiveDeref(mgr.getManager(),x[358].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[360].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[362].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[357].getNode());
	std::cerr<<"Appending gate to output[0] x[356]"<<std::endl;
	output[0]=output[0] & x[356];
		
	std::cerr<<"processing gate 372..."<<std::endl;
	x[372] = (!x[96]|x[95])&(!x[95]|x[96]);// and (not m_24_1 or m_24) and (not m_24 or m_24_1) 
	count_nodes_vector.push_back(x[372]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(372);
		
	std::cerr<<"processing gate 376..."<<std::endl;
	x[376] = (!x[98]|x[95]);// and (not g_24_2_1 or m_24) 
	count_nodes_vector.push_back(x[376]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(376);
	
	std::cerr<<"processing gate 378..."<<std::endl;
	x[378] = (!x[99]|x[95]);// and (not g_24_2_2 or m_24) 
	count_nodes_vector.push_back(x[378]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(378);
	
	std::cerr<<"processing gate 380..."<<std::endl;
	x[380] = (!x[100]|x[95]);// and (not g_24_2_3 or m_24) 
	count_nodes_vector.push_back(x[380]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(380);
	
	std::cerr<<"processing gate 382..."<<std::endl;
	x[382] = (!x[101]|x[95]);// and (not g_24_2_4 or m_24) 
	count_nodes_vector.push_back(x[382]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(382);
	
	std::cerr<<"processing gate 384..."<<std::endl;
	x[384] = (!x[102]|x[95]);// and (not g_24_2_5 or m_24) 
	count_nodes_vector.push_back(x[384]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(384);
	
	std::cerr<<"processing gate 386..."<<std::endl;
	x[386] = (!x[103]|x[95]);// and (not g_24_2_6 or m_24) 
	count_nodes_vector.push_back(x[386]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(386);
	
	std::cerr<<"processing gate 388..."<<std::endl;
	x[388] = (!x[104]|x[95]);// and (not g_24_2_7 or m_24) 
	count_nodes_vector.push_back(x[388]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(388);
	
	std::cerr<<"processing gate 390..."<<std::endl;
	x[390] = (!x[105]|x[95]);// and (not g_24_2_8 or m_24) 
	count_nodes_vector.push_back(x[390]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(390);
	
	std::cerr<<"processing gate 392..."<<std::endl;
	x[392] = (!x[106]|x[95]);// and (not g_24_2_9 or m_24) 
	count_nodes_vector.push_back(x[392]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(392);
	
	std::cerr<<"processing gate 394..."<<std::endl;
	x[394] = (!x[107]|x[95]);// and (not g_24_2_10 or m_24) 
	count_nodes_vector.push_back(x[394]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(394);
	
	std::cerr<<"processing gate 396..."<<std::endl;
	x[396] = (!x[108]|x[95]);// and (not g_24_2_11 or m_24) 
	count_nodes_vector.push_back(x[396]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(396);
	
	std::cerr<<"processing gate 398..."<<std::endl;
	x[398] = (!x[109]|x[95]);// and (not g_24_2_12 or m_24) 
	count_nodes_vector.push_back(x[398]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(398);
	
	std::cerr<<"processing gate 400..."<<std::endl;
	x[400] = (!x[110]|x[95]);// and (not g_24_2_13 or m_24) 
	count_nodes_vector.push_back(x[400]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(400);
	
	std::cerr<<"processing gate 402..."<<std::endl;
	x[402] = (!x[111]|x[95]);// and (not g_24_2_14 or m_24) 
	count_nodes_vector.push_back(x[402]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(402);
	
	std::cerr<<"processing gate 404..."<<std::endl;
	x[404] = (!x[112]|x[95]);// and (not g_24_2_15 or m_24) 
	count_nodes_vector.push_back(x[404]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(404);
	
	std::cerr<<"processing gate 406..."<<std::endl;
	x[406] = (!x[113]|x[95]);// and (not g_24_2_16 or m_24) 
	count_nodes_vector.push_back(x[406]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(406);
	
	std::cerr<<"processing gate 408..."<<std::endl;
	x[408] = (!x[114]|x[95]);// and (not g_24_2_17 or m_24) 
	count_nodes_vector.push_back(x[408]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(408);
	
	std::cerr<<"processing gate 410..."<<std::endl;
	x[410] = (!x[115]|x[95]);// and (not g_24_2_18 or m_24) 
	count_nodes_vector.push_back(x[410]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(410);
	
	std::cerr<<"processing gate 412..."<<std::endl;
	x[412] = (!x[116]|x[95]);// and (not g_24_2_19 or m_24) 
	count_nodes_vector.push_back(x[412]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(412);
	
	std::cerr<<"processing gate 414..."<<std::endl;
	x[414] = (!x[117]|x[95]);// and (not g_24_2_20 or m_24) 
	count_nodes_vector.push_back(x[414]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(414);
	
	std::cerr<<"processing gate 416..."<<std::endl;
	x[416] = (!x[118]|x[95]);// and (not g_24_2_21 or m_24) 
	count_nodes_vector.push_back(x[416]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(416);
	
	std::cerr<<"processing gate 418..."<<std::endl;
	x[418] = (!x[119]|x[95]);// and (not g_24_2_22 or m_24) 
	count_nodes_vector.push_back(x[418]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(418);
	
	std::cerr<<"processing gate 375..."<<std::endl;
	x[375] = (!x[95]|(x[98]|x[99]|x[100]|x[101]|x[102]|x[103]|x[104]|x[105]|x[106]|x[107]|x[108]|x[109]|x[110]|x[111]|x[112]|x[113]|x[114]|x[115]|x[116]|x[117]|x[118]|x[119]))&(!x[98]|!x[99])&(!x[98]|!x[100])&(!x[98]|!x[101])&(!x[98]|!x[102])&(!x[98]|!x[103])&(!x[98]|!x[104])&(!x[98]|!x[105])&(!x[98]|!x[106])&(!x[98]|!x[107])&(!x[98]|!x[108])&(!x[98]|!x[109])&(!x[98]|!x[110])&(!x[98]|!x[111])&(!x[98]|!x[112])&(!x[98]|!x[113])&(!x[98]|!x[114])&(!x[98]|!x[115])&(!x[98]|!x[116])&(!x[98]|!x[117])&(!x[98]|!x[118])&(!x[98]|!x[119])&(!x[99]|!x[100])&(!x[99]|!x[101])&(!x[99]|!x[102])&(!x[99]|!x[103])&(!x[99]|!x[104])&(!x[99]|!x[105])&(!x[99]|!x[106])&(!x[99]|!x[107])&(!x[99]|!x[108])&(!x[99]|!x[109])&(!x[99]|!x[110])&(!x[99]|!x[111])&(!x[99]|!x[112])&(!x[99]|!x[113])&(!x[99]|!x[114])&(!x[99]|!x[115])&(!x[99]|!x[116])&(!x[99]|!x[117])&(!x[99]|!x[118])&(!x[99]|!x[119])&(!x[100]|!x[101])&(!x[100]|!x[102])&(!x[100]|!x[103])&(!x[100]|!x[104])&(!x[100]|!x[105])&(!x[100]|!x[106])&(!x[100]|!x[107])&(!x[100]|!x[108])&(!x[100]|!x[109])&(!x[100]|!x[110])&(!x[100]|!x[111])&(!x[100]|!x[112])&(!x[100]|!x[113])&(!x[100]|!x[114])&(!x[100]|!x[115])&(!x[100]|!x[116])&(!x[100]|!x[117])&(!x[100]|!x[118])&(!x[100]|!x[119])&(!x[101]|!x[102])&(!x[101]|!x[103])&(!x[101]|!x[104])&(!x[101]|!x[105])&(!x[101]|!x[106])&(!x[101]|!x[107])&(!x[101]|!x[108])&(!x[101]|!x[109])&(!x[101]|!x[110])&(!x[101]|!x[111])&(!x[101]|!x[112])&(!x[101]|!x[113])&(!x[101]|!x[114])&(!x[101]|!x[115])&(!x[101]|!x[116])&(!x[101]|!x[117])&(!x[101]|!x[118])&(!x[101]|!x[119])&(!x[102]|!x[103])&(!x[102]|!x[104])&(!x[102]|!x[105])&(!x[102]|!x[106])&(!x[102]|!x[107])&(!x[102]|!x[108])&(!x[102]|!x[109])&(!x[102]|!x[110])&(!x[102]|!x[111])&(!x[102]|!x[112])&(!x[102]|!x[113])&(!x[102]|!x[114])&(!x[102]|!x[115])&(!x[102]|!x[116])&(!x[102]|!x[117])&(!x[102]|!x[118])&(!x[102]|!x[119])&(!x[103]|!x[104])&(!x[103]|!x[105])&(!x[103]|!x[106])&(!x[103]|!x[107])&(!x[103]|!x[108])&(!x[103]|!x[109])&(!x[103]|!x[110])&(!x[103]|!x[111])&(!x[103]|!x[112])&(!x[103]|!x[113])&(!x[103]|!x[114])&(!x[103]|!x[115])&(!x[103]|!x[116])&(!x[103]|!x[117])&(!x[103]|!x[118])&(!x[103]|!x[119])&(!x[104]|!x[105])&(!x[104]|!x[106])&(!x[104]|!x[107])&(!x[104]|!x[108])&(!x[104]|!x[109])&(!x[104]|!x[110])&(!x[104]|!x[111])&(!x[104]|!x[112])&(!x[104]|!x[113])&(!x[104]|!x[114])&(!x[104]|!x[115])&(!x[104]|!x[116])&(!x[104]|!x[117])&(!x[104]|!x[118])&(!x[104]|!x[119])&(!x[105]|!x[106])&(!x[105]|!x[107])&(!x[105]|!x[108])&(!x[105]|!x[109])&(!x[105]|!x[110])&(!x[105]|!x[111])&(!x[105]|!x[112])&(!x[105]|!x[113])&(!x[105]|!x[114])&(!x[105]|!x[115])&(!x[105]|!x[116])&(!x[105]|!x[117])&(!x[105]|!x[118])&(!x[105]|!x[119])&(!x[106]|!x[107])&(!x[106]|!x[108])&(!x[106]|!x[109])&(!x[106]|!x[110])&(!x[106]|!x[111])&(!x[106]|!x[112])&(!x[106]|!x[113])&(!x[106]|!x[114])&(!x[106]|!x[115])&(!x[106]|!x[116])&(!x[106]|!x[117])&(!x[106]|!x[118])&(!x[106]|!x[119])&(!x[107]|!x[108])&(!x[107]|!x[109])&(!x[107]|!x[110])&(!x[107]|!x[111])&(!x[107]|!x[112])&(!x[107]|!x[113])&(!x[107]|!x[114])&(!x[107]|!x[115])&(!x[107]|!x[116])&(!x[107]|!x[117])&(!x[107]|!x[118])&(!x[107]|!x[119])&(!x[108]|!x[109])&(!x[108]|!x[110])&(!x[108]|!x[111])&(!x[108]|!x[112])&(!x[108]|!x[113])&(!x[108]|!x[114])&(!x[108]|!x[115])&(!x[108]|!x[116])&(!x[108]|!x[117])&(!x[108]|!x[118])&(!x[108]|!x[119])&(!x[109]|!x[110])&(!x[109]|!x[111])&(!x[109]|!x[112])&(!x[109]|!x[113])&(!x[109]|!x[114])&(!x[109]|!x[115])&(!x[109]|!x[116])&(!x[109]|!x[117])&(!x[109]|!x[118])&(!x[109]|!x[119])&(!x[110]|!x[111])&(!x[110]|!x[112])&(!x[110]|!x[113])&(!x[110]|!x[114])&(!x[110]|!x[115])&(!x[110]|!x[116])&(!x[110]|!x[117])&(!x[110]|!x[118])&(!x[110]|!x[119])&(!x[111]|!x[112])&(!x[111]|!x[113])&(!x[111]|!x[114])&(!x[111]|!x[115])&(!x[111]|!x[116])&(!x[111]|!x[117])&(!x[111]|!x[118])&(!x[111]|!x[119])&(!x[112]|!x[113])&(!x[112]|!x[114])&(!x[112]|!x[115])&(!x[112]|!x[116])&(!x[112]|!x[117])&(!x[112]|!x[118])&(!x[112]|!x[119])&(!x[113]|!x[114])&(!x[113]|!x[115])&(!x[113]|!x[116])&(!x[113]|!x[117])&(!x[113]|!x[118])&(!x[113]|!x[119])&(!x[114]|!x[115])&(!x[114]|!x[116])&(!x[114]|!x[117])&(!x[114]|!x[118])&(!x[114]|!x[119])&(!x[115]|!x[116])&(!x[115]|!x[117])&(!x[115]|!x[118])&(!x[115]|!x[119])&(!x[116]|!x[117])&(!x[116]|!x[118])&(!x[116]|!x[119])&(!x[117]|!x[118])&(!x[117]|!x[119])&(!x[118]|!x[119]);// and (not m_24 or (g_24_2_1 or g_24_2_2 or g_24_2_3 or g_24_2_4 or g_24_2_5 or g_24_2_6 or g_24_2_7 or g_24_2_8 or g_24_2_9 or g_24_2_10 or g_24_2_11 or g_24_2_12 or g_24_2_13 or g_24_2_14 or g_24_2_15 or g_24_2_16 or g_24_2_17 or g_24_2_18 or g_24_2_19 or g_24_2_20 or g_24_2_21 or g_24_2_22)) and (not g_24_2_1 or not g_24_2_2) and (not g_24_2_1 or not g_24_2_3) and (not g_24_2_1 or not g_24_2_4) and (not g_24_2_1 or not g_24_2_5) and (not g_24_2_1 or not g_24_2_6) and (not g_24_2_1 or not g_24_2_7) and (not g_24_2_1 or not g_24_2_8) and (not g_24_2_1 or not g_24_2_9) and (not g_24_2_1 or not g_24_2_10) and (not g_24_2_1 or not g_24_2_11) and (not g_24_2_1 or not g_24_2_12) and (not g_24_2_1 or not g_24_2_13) and (not g_24_2_1 or not g_24_2_14) and (not g_24_2_1 or not g_24_2_15) and (not g_24_2_1 or not g_24_2_16) and (not g_24_2_1 or not g_24_2_17) and (not g_24_2_1 or not g_24_2_18) and (not g_24_2_1 or not g_24_2_19) and (not g_24_2_1 or not g_24_2_20) and (not g_24_2_1 or not g_24_2_21) and (not g_24_2_1 or not g_24_2_22) and (not g_24_2_2 or not g_24_2_3) and (not g_24_2_2 or not g_24_2_4) and (not g_24_2_2 or not g_24_2_5) and (not g_24_2_2 or not g_24_2_6) and (not g_24_2_2 or not g_24_2_7) and (not g_24_2_2 or not g_24_2_8) and (not g_24_2_2 or not g_24_2_9) and (not g_24_2_2 or not g_24_2_10) and (not g_24_2_2 or not g_24_2_11) and (not g_24_2_2 or not g_24_2_12) and (not g_24_2_2 or not g_24_2_13) and (not g_24_2_2 or not g_24_2_14) and (not g_24_2_2 or not g_24_2_15) and (not g_24_2_2 or not g_24_2_16) and (not g_24_2_2 or not g_24_2_17) and (not g_24_2_2 or not g_24_2_18) and (not g_24_2_2 or not g_24_2_19) and (not g_24_2_2 or not g_24_2_20) and (not g_24_2_2 or not g_24_2_21) and (not g_24_2_2 or not g_24_2_22) and (not g_24_2_3 or not g_24_2_4) and (not g_24_2_3 or not g_24_2_5) and (not g_24_2_3 or not g_24_2_6) and (not g_24_2_3 or not g_24_2_7) and (not g_24_2_3 or not g_24_2_8) and (not g_24_2_3 or not g_24_2_9) and (not g_24_2_3 or not g_24_2_10) and (not g_24_2_3 or not g_24_2_11) and (not g_24_2_3 or not g_24_2_12) and (not g_24_2_3 or not g_24_2_13) and (not g_24_2_3 or not g_24_2_14) and (not g_24_2_3 or not g_24_2_15) and (not g_24_2_3 or not g_24_2_16) and (not g_24_2_3 or not g_24_2_17) and (not g_24_2_3 or not g_24_2_18) and (not g_24_2_3 or not g_24_2_19) and (not g_24_2_3 or not g_24_2_20) and (not g_24_2_3 or not g_24_2_21) and (not g_24_2_3 or not g_24_2_22) and (not g_24_2_4 or not g_24_2_5) and (not g_24_2_4 or not g_24_2_6) and (not g_24_2_4 or not g_24_2_7) and (not g_24_2_4 or not g_24_2_8) and (not g_24_2_4 or not g_24_2_9) and (not g_24_2_4 or not g_24_2_10) and (not g_24_2_4 or not g_24_2_11) and (not g_24_2_4 or not g_24_2_12) and (not g_24_2_4 or not g_24_2_13) and (not g_24_2_4 or not g_24_2_14) and (not g_24_2_4 or not g_24_2_15) and (not g_24_2_4 or not g_24_2_16) and (not g_24_2_4 or not g_24_2_17) and (not g_24_2_4 or not g_24_2_18) and (not g_24_2_4 or not g_24_2_19) and (not g_24_2_4 or not g_24_2_20) and (not g_24_2_4 or not g_24_2_21) and (not g_24_2_4 or not g_24_2_22) and (not g_24_2_5 or not g_24_2_6) and (not g_24_2_5 or not g_24_2_7) and (not g_24_2_5 or not g_24_2_8) and (not g_24_2_5 or not g_24_2_9) and (not g_24_2_5 or not g_24_2_10) and (not g_24_2_5 or not g_24_2_11) and (not g_24_2_5 or not g_24_2_12) and (not g_24_2_5 or not g_24_2_13) and (not g_24_2_5 or not g_24_2_14) and (not g_24_2_5 or not g_24_2_15) and (not g_24_2_5 or not g_24_2_16) and (not g_24_2_5 or not g_24_2_17) and (not g_24_2_5 or not g_24_2_18) and (not g_24_2_5 or not g_24_2_19) and (not g_24_2_5 or not g_24_2_20) and (not g_24_2_5 or not g_24_2_21) and (not g_24_2_5 or not g_24_2_22) and (not g_24_2_6 or not g_24_2_7) and (not g_24_2_6 or not g_24_2_8) and (not g_24_2_6 or not g_24_2_9) and (not g_24_2_6 or not g_24_2_10) and (not g_24_2_6 or not g_24_2_11) and (not g_24_2_6 or not g_24_2_12) and (not g_24_2_6 or not g_24_2_13) and (not g_24_2_6 or not g_24_2_14) and (not g_24_2_6 or not g_24_2_15) and (not g_24_2_6 or not g_24_2_16) and (not g_24_2_6 or not g_24_2_17) and (not g_24_2_6 or not g_24_2_18) and (not g_24_2_6 or not g_24_2_19) and (not g_24_2_6 or not g_24_2_20) and (not g_24_2_6 or not g_24_2_21) and (not g_24_2_6 or not g_24_2_22) and (not g_24_2_7 or not g_24_2_8) and (not g_24_2_7 or not g_24_2_9) and (not g_24_2_7 or not g_24_2_10) and (not g_24_2_7 or not g_24_2_11) and (not g_24_2_7 or not g_24_2_12) and (not g_24_2_7 or not g_24_2_13) and (not g_24_2_7 or not g_24_2_14) and (not g_24_2_7 or not g_24_2_15) and (not g_24_2_7 or not g_24_2_16) and (not g_24_2_7 or not g_24_2_17) and (not g_24_2_7 or not g_24_2_18) and (not g_24_2_7 or not g_24_2_19) and (not g_24_2_7 or not g_24_2_20) and (not g_24_2_7 or not g_24_2_21) and (not g_24_2_7 or not g_24_2_22) and (not g_24_2_8 or not g_24_2_9) and (not g_24_2_8 or not g_24_2_10) and (not g_24_2_8 or not g_24_2_11) and (not g_24_2_8 or not g_24_2_12) and (not g_24_2_8 or not g_24_2_13) and (not g_24_2_8 or not g_24_2_14) and (not g_24_2_8 or not g_24_2_15) and (not g_24_2_8 or not g_24_2_16) and (not g_24_2_8 or not g_24_2_17) and (not g_24_2_8 or not g_24_2_18) and (not g_24_2_8 or not g_24_2_19) and (not g_24_2_8 or not g_24_2_20) and (not g_24_2_8 or not g_24_2_21) and (not g_24_2_8 or not g_24_2_22) and (not g_24_2_9 or not g_24_2_10) and (not g_24_2_9 or not g_24_2_11) and (not g_24_2_9 or not g_24_2_12) and (not g_24_2_9 or not g_24_2_13) and (not g_24_2_9 or not g_24_2_14) and (not g_24_2_9 or not g_24_2_15) and (not g_24_2_9 or not g_24_2_16) and (not g_24_2_9 or not g_24_2_17) and (not g_24_2_9 or not g_24_2_18) and (not g_24_2_9 or not g_24_2_19) and (not g_24_2_9 or not g_24_2_20) and (not g_24_2_9 or not g_24_2_21) and (not g_24_2_9 or not g_24_2_22) and (not g_24_2_10 or not g_24_2_11) and (not g_24_2_10 or not g_24_2_12) and (not g_24_2_10 or not g_24_2_13) and (not g_24_2_10 or not g_24_2_14) and (not g_24_2_10 or not g_24_2_15) and (not g_24_2_10 or not g_24_2_16) and (not g_24_2_10 or not g_24_2_17) and (not g_24_2_10 or not g_24_2_18) and (not g_24_2_10 or not g_24_2_19) and (not g_24_2_10 or not g_24_2_20) and (not g_24_2_10 or not g_24_2_21) and (not g_24_2_10 or not g_24_2_22) and (not g_24_2_11 or not g_24_2_12) and (not g_24_2_11 or not g_24_2_13) and (not g_24_2_11 or not g_24_2_14) and (not g_24_2_11 or not g_24_2_15) and (not g_24_2_11 or not g_24_2_16) and (not g_24_2_11 or not g_24_2_17) and (not g_24_2_11 or not g_24_2_18) and (not g_24_2_11 or not g_24_2_19) and (not g_24_2_11 or not g_24_2_20) and (not g_24_2_11 or not g_24_2_21) and (not g_24_2_11 or not g_24_2_22) and (not g_24_2_12 or not g_24_2_13) and (not g_24_2_12 or not g_24_2_14) and (not g_24_2_12 or not g_24_2_15) and (not g_24_2_12 or not g_24_2_16) and (not g_24_2_12 or not g_24_2_17) and (not g_24_2_12 or not g_24_2_18) and (not g_24_2_12 or not g_24_2_19) and (not g_24_2_12 or not g_24_2_20) and (not g_24_2_12 or not g_24_2_21) and (not g_24_2_12 or not g_24_2_22) and (not g_24_2_13 or not g_24_2_14) and (not g_24_2_13 or not g_24_2_15) and (not g_24_2_13 or not g_24_2_16) and (not g_24_2_13 or not g_24_2_17) and (not g_24_2_13 or not g_24_2_18) and (not g_24_2_13 or not g_24_2_19) and (not g_24_2_13 or not g_24_2_20) and (not g_24_2_13 or not g_24_2_21) and (not g_24_2_13 or not g_24_2_22) and (not g_24_2_14 or not g_24_2_15) and (not g_24_2_14 or not g_24_2_16) and (not g_24_2_14 or not g_24_2_17) and (not g_24_2_14 or not g_24_2_18) and (not g_24_2_14 or not g_24_2_19) and (not g_24_2_14 or not g_24_2_20) and (not g_24_2_14 or not g_24_2_21) and (not g_24_2_14 or not g_24_2_22) and (not g_24_2_15 or not g_24_2_16) and (not g_24_2_15 or not g_24_2_17) and (not g_24_2_15 or not g_24_2_18) and (not g_24_2_15 or not g_24_2_19) and (not g_24_2_15 or not g_24_2_20) and (not g_24_2_15 or not g_24_2_21) and (not g_24_2_15 or not g_24_2_22) and (not g_24_2_16 or not g_24_2_17) and (not g_24_2_16 or not g_24_2_18) and (not g_24_2_16 or not g_24_2_19) and (not g_24_2_16 or not g_24_2_20) and (not g_24_2_16 or not g_24_2_21) and (not g_24_2_16 or not g_24_2_22) and (not g_24_2_17 or not g_24_2_18) and (not g_24_2_17 or not g_24_2_19) and (not g_24_2_17 or not g_24_2_20) and (not g_24_2_17 or not g_24_2_21) and (not g_24_2_17 or not g_24_2_22) and (not g_24_2_18 or not g_24_2_19) and (not g_24_2_18 or not g_24_2_20) and (not g_24_2_18 or not g_24_2_21) and (not g_24_2_18 or not g_24_2_22) and (not g_24_2_19 or not g_24_2_20) and (not g_24_2_19 or not g_24_2_21) and (not g_24_2_19 or not g_24_2_22) and (not g_24_2_20 or not g_24_2_21) and (not g_24_2_20 or not g_24_2_22) and (not g_24_2_21 or not g_24_2_22) 
	count_nodes_vector.push_back(x[375]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(375);
	std::cerr<<"processing gate 374..."<<std::endl;
	x[374] = x[376]&x[378]&x[380]&x[382]&x[384]&x[386]&x[388]&x[390]&x[392]&x[394]&x[396]&x[398]&x[400]&x[402]&x[404]&x[406]&x[408]&x[410]&x[412]&x[414]&x[416]&x[418]&x[375];//
	count_nodes_vector.push_back(x[374]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(374);
	Cudd_RecursiveDeref(mgr.getManager(),x[376].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[378].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[380].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[382].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[384].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[386].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[388].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[390].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[392].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[394].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[396].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[398].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[400].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[402].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[404].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[406].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[408].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[410].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[412].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[414].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[416].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[418].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[375].getNode());
	
	std::cerr<<"processing gate 420..."<<std::endl;
	x[420] = (!x[120]|x[95])&(!x[95]|x[120]);// and (not m_24_3 or m_24) and (not m_24 or m_24_3) 
	count_nodes_vector.push_back(x[420]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(420);
	
	std::cerr<<"processing gate 371..."<<std::endl;
	x[371] = (!x[95]|x[0])&(!x[0]|x[95]);// and (not m_24 or R) and (not R or m_24) 
	count_nodes_vector.push_back(x[371]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(371);
	std::cerr<<"processing gate 370..."<<std::endl;
	x[370] = x[372]&x[374]&x[420]&x[371];//
	count_nodes_vector.push_back(x[370]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(370);
	Cudd_RecursiveDeref(mgr.getManager(),x[372].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[374].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[420].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[371].getNode());
	std::cerr<<"Appending gate to output[0] x[370]"<<std::endl;
	output[0]=output[0] & x[370];
		
	std::cerr<<"processing gate 424..."<<std::endl;
	x[424] = (!x[122]|x[121]);// and (not o_25_1 or o_25) 
	count_nodes_vector.push_back(x[424]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(424);
	
	std::cerr<<"processing gate 426..."<<std::endl;
	x[426] = (!x[123]|x[121])&(!x[121]|x[123]);// and (not m_25_2 or o_25) and (not o_25 or m_25_2) 
	count_nodes_vector.push_back(x[426]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(426);
	
	std::cerr<<"processing gate 428..."<<std::endl;
	x[428] = (!x[124]|x[121])&(!x[121]|x[124]);// and (not m_25_3 or o_25) and (not o_25 or m_25_3) 
	count_nodes_vector.push_back(x[428]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(428);
	
	std::cerr<<"processing gate 423..."<<std::endl;
	x[423] = (!x[121]|x[0]);// and (not o_25 or R) 
	count_nodes_vector.push_back(x[423]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(423);
	std::cerr<<"processing gate 422..."<<std::endl;
	x[422] = x[424]&x[426]&x[428]&x[423];//
	count_nodes_vector.push_back(x[422]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(422);
	Cudd_RecursiveDeref(mgr.getManager(),x[424].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[426].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[428].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[423].getNode());
	std::cerr<<"Appending gate to output[0] x[422]"<<std::endl;
	output[0]=output[0] & x[422];
		
	std::cerr<<"processing gate 432..."<<std::endl;
	x[432] = (!x[126]|x[125]);// and (not o_26_1 or m_26) 
	count_nodes_vector.push_back(x[432]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(432);
	
	std::cerr<<"processing gate 434..."<<std::endl;
	x[434] = (!x[127]|x[125])&(!x[125]|x[127]);// and (not m_26_2 or m_26) and (not m_26 or m_26_2) 
	count_nodes_vector.push_back(x[434]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(434);
	
	std::cerr<<"processing gate 436..."<<std::endl;
	x[436] = (!x[128]|x[125]);// and (not o_26_3 or m_26) 
	count_nodes_vector.push_back(x[436]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(436);
	
	std::cerr<<"processing gate 431..."<<std::endl;
	x[431] = (!x[125]|x[0])&(!x[0]|x[125]);// and (not m_26 or R) and (not R or m_26) 
	count_nodes_vector.push_back(x[431]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(431);
	std::cerr<<"processing gate 430..."<<std::endl;
	x[430] = x[432]&x[434]&x[436]&x[431];//
	count_nodes_vector.push_back(x[430]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(430);
	Cudd_RecursiveDeref(mgr.getManager(),x[432].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[434].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[436].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[431].getNode());
	std::cerr<<"Appending gate to output[0] x[430]"<<std::endl;
	output[0]=output[0] & x[430];
		
	std::cerr<<"processing gate 440..."<<std::endl;
	x[440] = (!x[130]|x[129]);// and (not o_27_1 or m_27) 
	count_nodes_vector.push_back(x[440]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(440);
	
	std::cerr<<"processing gate 442..."<<std::endl;
	x[442] = (!x[131]|x[129]);// and (not o_27_2 or m_27) 
	count_nodes_vector.push_back(x[442]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(442);
	
	std::cerr<<"processing gate 444..."<<std::endl;
	x[444] = (!x[132]|x[129])&(!x[129]|x[132]);// and (not m_27_3 or m_27) and (not m_27 or m_27_3) 
	count_nodes_vector.push_back(x[444]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(444);
	
	std::cerr<<"processing gate 439..."<<std::endl;
	x[439] = (!x[129]|x[0])&(!x[0]|x[129]);// and (not m_27 or R) and (not R or m_27) 
	count_nodes_vector.push_back(x[439]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(439);
	std::cerr<<"processing gate 438..."<<std::endl;
	x[438] = x[440]&x[442]&x[444]&x[439];//
	count_nodes_vector.push_back(x[438]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(438);
	Cudd_RecursiveDeref(mgr.getManager(),x[440].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[442].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[444].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[439].getNode());
	std::cerr<<"Appending gate to output[0] x[438]"<<std::endl;
	output[0]=output[0] & x[438];
		
	std::cerr<<"processing gate 448..."<<std::endl;
	x[448] = (!x[134]|x[133])&(!x[133]|x[134]);// and (not m_28_1 or m_28) and (not m_28 or m_28_1) 
	count_nodes_vector.push_back(x[448]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(448);
	
	std::cerr<<"processing gate 450..."<<std::endl;
	x[450] = (!x[135]|x[133]);// and (not o_28_2 or m_28) 
	count_nodes_vector.push_back(x[450]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(450);
	
	std::cerr<<"processing gate 452..."<<std::endl;
	x[452] = (!x[136]|x[133])&(!x[133]|x[136]);// and (not m_28_3 or m_28) and (not m_28 or m_28_3) 
	count_nodes_vector.push_back(x[452]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(452);
	
	std::cerr<<"processing gate 447..."<<std::endl;
	x[447] = (!x[133]|x[0])&(!x[0]|x[133]);// and (not m_28 or R) and (not R or m_28) 
	count_nodes_vector.push_back(x[447]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(447);
	std::cerr<<"processing gate 446..."<<std::endl;
	x[446] = x[448]&x[450]&x[452]&x[447];//
	count_nodes_vector.push_back(x[446]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(446);
	Cudd_RecursiveDeref(mgr.getManager(),x[448].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[450].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[452].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[447].getNode());
	std::cerr<<"Appending gate to output[0] x[446]"<<std::endl;
	output[0]=output[0] & x[446];
		
	std::cerr<<"processing gate 456..."<<std::endl;
	x[456] = (!x[138]|x[137]);// and (not o_29_1 or m_29) 
	count_nodes_vector.push_back(x[456]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(456);
	
	std::cerr<<"processing gate 458..."<<std::endl;
	x[458] = (!x[139]|x[137])&(!x[137]|x[139]);// and (not m_29_2 or m_29) and (not m_29 or m_29_2) 
	count_nodes_vector.push_back(x[458]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(458);
		
	std::cerr<<"processing gate 462..."<<std::endl;
	x[462] = (!x[141]|x[137]);// and (not g_29_3_1 or m_29) 
	count_nodes_vector.push_back(x[462]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(462);
	
	std::cerr<<"processing gate 464..."<<std::endl;
	x[464] = (!x[142]|x[137]);// and (not g_29_3_2 or m_29) 
	count_nodes_vector.push_back(x[464]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(464);
	
	std::cerr<<"processing gate 466..."<<std::endl;
	x[466] = (!x[143]|x[137]);// and (not g_29_3_3 or m_29) 
	count_nodes_vector.push_back(x[466]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(466);
	
	std::cerr<<"processing gate 468..."<<std::endl;
	x[468] = (!x[144]|x[137]);// and (not g_29_3_4 or m_29) 
	count_nodes_vector.push_back(x[468]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(468);
	
	std::cerr<<"processing gate 470..."<<std::endl;
	x[470] = (!x[145]|x[137]);// and (not g_29_3_5 or m_29) 
	count_nodes_vector.push_back(x[470]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(470);
	
	std::cerr<<"processing gate 472..."<<std::endl;
	x[472] = (!x[146]|x[137]);// and (not g_29_3_6 or m_29) 
	count_nodes_vector.push_back(x[472]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(472);
	
	std::cerr<<"processing gate 474..."<<std::endl;
	x[474] = (!x[147]|x[137]);// and (not g_29_3_7 or m_29) 
	count_nodes_vector.push_back(x[474]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(474);
	
	std::cerr<<"processing gate 476..."<<std::endl;
	x[476] = (!x[148]|x[137]);// and (not g_29_3_8 or m_29) 
	count_nodes_vector.push_back(x[476]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(476);
	
	std::cerr<<"processing gate 478..."<<std::endl;
	x[478] = (!x[149]|x[137]);// and (not g_29_3_9 or m_29) 
	count_nodes_vector.push_back(x[478]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(478);
	
	std::cerr<<"processing gate 480..."<<std::endl;
	x[480] = (!x[150]|x[137]);// and (not g_29_3_10 or m_29) 
	count_nodes_vector.push_back(x[480]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(480);
	
	std::cerr<<"processing gate 461..."<<std::endl;
	x[461] = (!x[137]|(x[141]|x[142]|x[143]|x[144]|x[145]|x[146]|x[147]|x[148]|x[149]|x[150]))&(!x[141]|!x[142])&(!x[141]|!x[143])&(!x[141]|!x[144])&(!x[141]|!x[145])&(!x[141]|!x[146])&(!x[141]|!x[147])&(!x[141]|!x[148])&(!x[141]|!x[149])&(!x[141]|!x[150])&(!x[142]|!x[143])&(!x[142]|!x[144])&(!x[142]|!x[145])&(!x[142]|!x[146])&(!x[142]|!x[147])&(!x[142]|!x[148])&(!x[142]|!x[149])&(!x[142]|!x[150])&(!x[143]|!x[144])&(!x[143]|!x[145])&(!x[143]|!x[146])&(!x[143]|!x[147])&(!x[143]|!x[148])&(!x[143]|!x[149])&(!x[143]|!x[150])&(!x[144]|!x[145])&(!x[144]|!x[146])&(!x[144]|!x[147])&(!x[144]|!x[148])&(!x[144]|!x[149])&(!x[144]|!x[150])&(!x[145]|!x[146])&(!x[145]|!x[147])&(!x[145]|!x[148])&(!x[145]|!x[149])&(!x[145]|!x[150])&(!x[146]|!x[147])&(!x[146]|!x[148])&(!x[146]|!x[149])&(!x[146]|!x[150])&(!x[147]|!x[148])&(!x[147]|!x[149])&(!x[147]|!x[150])&(!x[148]|!x[149])&(!x[148]|!x[150])&(!x[149]|!x[150]);// and (not m_29 or (g_29_3_1 or g_29_3_2 or g_29_3_3 or g_29_3_4 or g_29_3_5 or g_29_3_6 or g_29_3_7 or g_29_3_8 or g_29_3_9 or g_29_3_10)) and (not g_29_3_1 or not g_29_3_2) and (not g_29_3_1 or not g_29_3_3) and (not g_29_3_1 or not g_29_3_4) and (not g_29_3_1 or not g_29_3_5) and (not g_29_3_1 or not g_29_3_6) and (not g_29_3_1 or not g_29_3_7) and (not g_29_3_1 or not g_29_3_8) and (not g_29_3_1 or not g_29_3_9) and (not g_29_3_1 or not g_29_3_10) and (not g_29_3_2 or not g_29_3_3) and (not g_29_3_2 or not g_29_3_4) and (not g_29_3_2 or not g_29_3_5) and (not g_29_3_2 or not g_29_3_6) and (not g_29_3_2 or not g_29_3_7) and (not g_29_3_2 or not g_29_3_8) and (not g_29_3_2 or not g_29_3_9) and (not g_29_3_2 or not g_29_3_10) and (not g_29_3_3 or not g_29_3_4) and (not g_29_3_3 or not g_29_3_5) and (not g_29_3_3 or not g_29_3_6) and (not g_29_3_3 or not g_29_3_7) and (not g_29_3_3 or not g_29_3_8) and (not g_29_3_3 or not g_29_3_9) and (not g_29_3_3 or not g_29_3_10) and (not g_29_3_4 or not g_29_3_5) and (not g_29_3_4 or not g_29_3_6) and (not g_29_3_4 or not g_29_3_7) and (not g_29_3_4 or not g_29_3_8) and (not g_29_3_4 or not g_29_3_9) and (not g_29_3_4 or not g_29_3_10) and (not g_29_3_5 or not g_29_3_6) and (not g_29_3_5 or not g_29_3_7) and (not g_29_3_5 or not g_29_3_8) and (not g_29_3_5 or not g_29_3_9) and (not g_29_3_5 or not g_29_3_10) and (not g_29_3_6 or not g_29_3_7) and (not g_29_3_6 or not g_29_3_8) and (not g_29_3_6 or not g_29_3_9) and (not g_29_3_6 or not g_29_3_10) and (not g_29_3_7 or not g_29_3_8) and (not g_29_3_7 or not g_29_3_9) and (not g_29_3_7 or not g_29_3_10) and (not g_29_3_8 or not g_29_3_9) and (not g_29_3_8 or not g_29_3_10) and (not g_29_3_9 or not g_29_3_10) 
	count_nodes_vector.push_back(x[461]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(461);
	std::cerr<<"processing gate 460..."<<std::endl;
	x[460] = x[462]&x[464]&x[466]&x[468]&x[470]&x[472]&x[474]&x[476]&x[478]&x[480]&x[461];//
	count_nodes_vector.push_back(x[460]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(460);
	Cudd_RecursiveDeref(mgr.getManager(),x[462].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[464].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[466].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[468].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[470].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[472].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[474].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[476].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[478].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[480].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[461].getNode());
	
	std::cerr<<"processing gate 455..."<<std::endl;
	x[455] = (!x[137]|x[0])&(!x[0]|x[137]);// and (not m_29 or R) and (not R or m_29) 
	count_nodes_vector.push_back(x[455]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(455);
	std::cerr<<"processing gate 454..."<<std::endl;
	x[454] = x[456]&x[458]&x[460]&x[455];//
	count_nodes_vector.push_back(x[454]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(454);
	Cudd_RecursiveDeref(mgr.getManager(),x[456].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[458].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[460].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[455].getNode());
	std::cerr<<"Appending gate to output[0] x[454]"<<std::endl;
	output[0]=output[0] & x[454];
		
	std::cerr<<"processing gate 484..."<<std::endl;
	x[484] = (!x[152]|x[151])&(!x[151]|x[152]);// and (not m_30_1 or o_30) and (not o_30 or m_30_1) 
	count_nodes_vector.push_back(x[484]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(484);
	
	std::cerr<<"processing gate 486..."<<std::endl;
	x[486] = (!x[153]|x[151])&(!x[151]|x[153]);// and (not m_30_2 or o_30) and (not o_30 or m_30_2) 
	count_nodes_vector.push_back(x[486]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(486);
	
	std::cerr<<"processing gate 488..."<<std::endl;
	x[488] = (!x[154]|x[151]);// and (not o_30_3 or o_30) 
	count_nodes_vector.push_back(x[488]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(488);
	
	std::cerr<<"processing gate 483..."<<std::endl;
	x[483] = (!x[151]|x[0]);// and (not o_30 or R) 
	count_nodes_vector.push_back(x[483]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(483);
	std::cerr<<"processing gate 482..."<<std::endl;
	x[482] = x[484]&x[486]&x[488]&x[483];//
	count_nodes_vector.push_back(x[482]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(482);
	Cudd_RecursiveDeref(mgr.getManager(),x[484].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[486].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[488].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[483].getNode());
	std::cerr<<"Appending gate to output[0] x[482]"<<std::endl;
	output[0]=output[0] & x[482];
		
	std::cerr<<"processing gate 492..."<<std::endl;
	x[492] = (!x[156]|x[155])&(!x[155]|x[156]);// and (not m_31_1 or o_31) and (not o_31 or m_31_1) 
	count_nodes_vector.push_back(x[492]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(492);
	
	std::cerr<<"processing gate 494..."<<std::endl;
	x[494] = (!x[157]|x[155]);// and (not o_31_2 or o_31) 
	count_nodes_vector.push_back(x[494]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(494);
	
	std::cerr<<"processing gate 496..."<<std::endl;
	x[496] = (!x[158]|x[155])&(!x[155]|x[158]);// and (not m_31_3 or o_31) and (not o_31 or m_31_3) 
	count_nodes_vector.push_back(x[496]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(496);
	
	std::cerr<<"processing gate 491..."<<std::endl;
	x[491] = (!x[155]|x[0]);// and (not o_31 or R) 
	count_nodes_vector.push_back(x[491]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(491);
	std::cerr<<"processing gate 490..."<<std::endl;
	x[490] = x[492]&x[494]&x[496]&x[491];//
	count_nodes_vector.push_back(x[490]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(490);
	Cudd_RecursiveDeref(mgr.getManager(),x[492].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[494].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[496].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[491].getNode());
	std::cerr<<"Appending gate to output[0] x[490]"<<std::endl;
	output[0]=output[0] & x[490];
		
	std::cerr<<"processing gate 500..."<<std::endl;
	x[500] = (!x[160]|x[159]);// and (not o_32_1 or o_32) 
	count_nodes_vector.push_back(x[500]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(500);
		
	std::cerr<<"processing gate 504..."<<std::endl;
	x[504] = (!x[162]|x[159]);// and (not g_32_2_1 or o_32) 
	count_nodes_vector.push_back(x[504]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(504);
	
	std::cerr<<"processing gate 506..."<<std::endl;
	x[506] = (!x[163]|x[159]);// and (not g_32_2_2 or o_32) 
	count_nodes_vector.push_back(x[506]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(506);
	
	std::cerr<<"processing gate 508..."<<std::endl;
	x[508] = (!x[164]|x[159]);// and (not g_32_2_3 or o_32) 
	count_nodes_vector.push_back(x[508]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(508);
	
	std::cerr<<"processing gate 510..."<<std::endl;
	x[510] = (!x[165]|x[159]);// and (not g_32_2_4 or o_32) 
	count_nodes_vector.push_back(x[510]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(510);
	
	std::cerr<<"processing gate 512..."<<std::endl;
	x[512] = (!x[166]|x[159]);// and (not g_32_2_5 or o_32) 
	count_nodes_vector.push_back(x[512]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(512);
	
	std::cerr<<"processing gate 514..."<<std::endl;
	x[514] = (!x[167]|x[159]);// and (not g_32_2_6 or o_32) 
	count_nodes_vector.push_back(x[514]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(514);
	
	std::cerr<<"processing gate 516..."<<std::endl;
	x[516] = (!x[168]|x[159]);// and (not g_32_2_7 or o_32) 
	count_nodes_vector.push_back(x[516]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(516);
	
	std::cerr<<"processing gate 503..."<<std::endl;
	x[503] = (!x[159]|(x[162]|x[163]|x[164]|x[165]|x[166]|x[167]|x[168]))&(!x[162]|!x[163])&(!x[162]|!x[164])&(!x[162]|!x[165])&(!x[162]|!x[166])&(!x[162]|!x[167])&(!x[162]|!x[168])&(!x[163]|!x[164])&(!x[163]|!x[165])&(!x[163]|!x[166])&(!x[163]|!x[167])&(!x[163]|!x[168])&(!x[164]|!x[165])&(!x[164]|!x[166])&(!x[164]|!x[167])&(!x[164]|!x[168])&(!x[165]|!x[166])&(!x[165]|!x[167])&(!x[165]|!x[168])&(!x[166]|!x[167])&(!x[166]|!x[168])&(!x[167]|!x[168]);// and (not o_32 or (g_32_2_1 or g_32_2_2 or g_32_2_3 or g_32_2_4 or g_32_2_5 or g_32_2_6 or g_32_2_7)) and (not g_32_2_1 or not g_32_2_2) and (not g_32_2_1 or not g_32_2_3) and (not g_32_2_1 or not g_32_2_4) and (not g_32_2_1 or not g_32_2_5) and (not g_32_2_1 or not g_32_2_6) and (not g_32_2_1 or not g_32_2_7) and (not g_32_2_2 or not g_32_2_3) and (not g_32_2_2 or not g_32_2_4) and (not g_32_2_2 or not g_32_2_5) and (not g_32_2_2 or not g_32_2_6) and (not g_32_2_2 or not g_32_2_7) and (not g_32_2_3 or not g_32_2_4) and (not g_32_2_3 or not g_32_2_5) and (not g_32_2_3 or not g_32_2_6) and (not g_32_2_3 or not g_32_2_7) and (not g_32_2_4 or not g_32_2_5) and (not g_32_2_4 or not g_32_2_6) and (not g_32_2_4 or not g_32_2_7) and (not g_32_2_5 or not g_32_2_6) and (not g_32_2_5 or not g_32_2_7) and (not g_32_2_6 or not g_32_2_7) 
	count_nodes_vector.push_back(x[503]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(503);
	std::cerr<<"processing gate 502..."<<std::endl;
	x[502] = x[504]&x[506]&x[508]&x[510]&x[512]&x[514]&x[516]&x[503];//
	count_nodes_vector.push_back(x[502]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(502);
	Cudd_RecursiveDeref(mgr.getManager(),x[504].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[506].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[508].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[510].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[512].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[514].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[516].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[503].getNode());
	
	std::cerr<<"processing gate 499..."<<std::endl;
	x[499] = (!x[159]|x[0]);// and (not o_32 or R) 
	count_nodes_vector.push_back(x[499]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(499);
	std::cerr<<"processing gate 498..."<<std::endl;
	x[498] = x[500]&x[502]&x[499];//
	count_nodes_vector.push_back(x[498]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(498);
	Cudd_RecursiveDeref(mgr.getManager(),x[500].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[502].getNode());
	Cudd_RecursiveDeref(mgr.getManager(),x[499].getNode());
	std::cerr<<"Appending gate to output[0] x[498]"<<std::endl;
	output[0]=output[0] & x[498];
	
	std::cerr<<"processing gate 518..."<<std::endl;
	x[518] = (!x[169]|x[0]);// and (not o_33 or R) 
	count_nodes_vector.push_back(x[518]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(518);
	std::cerr<<"Appending gate to output[0] x[518]"<<std::endl;
	output[0]=output[0] & x[518];
	
	std::cerr<<"processing gate 520..."<<std::endl;
	x[520] = (!x[170]|x[0]);// and (not o_34 or R) 
	count_nodes_vector.push_back(x[520]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(520);
	std::cerr<<"Appending gate to output[0] x[520]"<<std::endl;
	output[0]=output[0] & x[520];
	
	std::cerr<<"processing gate 522..."<<std::endl;
	x[522] = (!x[171]|x[0])&(!x[0]|x[171]);// and (not m_35 or R) and (not R or m_35) 
	count_nodes_vector.push_back(x[522]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(522);
	std::cerr<<"Appending gate to output[0] x[522]"<<std::endl;
	output[0]=output[0] & x[522];
	
	std::cerr<<"processing gate 524..."<<std::endl;
	x[524] = (!x[172]|x[0])&(!x[0]|x[172]);// and (not m_36 or R) and (not R or m_36) 
	count_nodes_vector.push_back(x[524]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(524);
	std::cerr<<"Appending gate to output[0] x[524]"<<std::endl;
	output[0]=output[0] & x[524];
	
	std::cerr<<"processing gate 526..."<<std::endl;
	x[526] = (!x[173]|x[0])&(!x[0]|x[173]);// and (not m_37 or R) and (not R or m_37) 
	count_nodes_vector.push_back(x[526]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(526);
	std::cerr<<"Appending gate to output[0] x[526]"<<std::endl;
	output[0]=output[0] & x[526];
	
	std::cerr<<"processing gate 528..."<<std::endl;
	x[528] = (!x[174]|x[0])&(!x[0]|x[174]);// and (not m_38 or R) and (not R or m_38) 
	count_nodes_vector.push_back(x[528]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(528);
	std::cerr<<"Appending gate to output[0] x[528]"<<std::endl;
	output[0]=output[0] & x[528];
	
	std::cerr<<"processing gate 530..."<<std::endl;
	x[530] = (!x[175]|x[0]);// and (not o_39 or R) 
	count_nodes_vector.push_back(x[530]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(530);
	std::cerr<<"Appending gate to output[0] x[530]"<<std::endl;
	output[0]=output[0] & x[530];
	
	std::cerr<<"processing gate 532..."<<std::endl;
	x[532] = (!x[176]|x[0])&(!x[0]|x[176]);// and (not m_40 or R) and (not R or m_40) 
	count_nodes_vector.push_back(x[532]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(532);
	std::cerr<<"Appending gate to output[0] x[532]"<<std::endl;
	output[0]=output[0] & x[532];
	
	std::cerr<<"processing gate 534..."<<std::endl;
	x[534] = (!x[177]|x[0])&(!x[0]|x[177]);// and (not m_41 or R) and (not R or m_41) 
	count_nodes_vector.push_back(x[534]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(534);
	std::cerr<<"Appending gate to output[0] x[534]"<<std::endl;
	output[0]=output[0] & x[534];
	
	std::cerr<<"processing gate 536..."<<std::endl;
	x[536] = (!x[178]|x[0])&(!x[0]|x[178]);// and (not m_42 or R) and (not R or m_42) 
	count_nodes_vector.push_back(x[536]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(536);
	std::cerr<<"Appending gate to output[0] x[536]"<<std::endl;
	output[0]=output[0] & x[536];
	
	std::cerr<<"processing gate 538..."<<std::endl;
	x[538] = (!x[179]|x[0]);// and (not o_43 or R) 
	count_nodes_vector.push_back(x[538]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(538);
	std::cerr<<"Appending gate to output[0] x[538]"<<std::endl;
	output[0]=output[0] & x[538];
	
	std::cerr<<"processing gate 181..."<<std::endl;
	x[181] = (x[0]);//(R) 
	count_nodes_vector.push_back(x[181]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(181);
	std::cerr<<"Appending gate to output[0] x[181]"<<std::endl;
	output[0]=output[0] & x[181];
		
	std::cerr<<"processing gate 542..."<<std::endl;
	x[541] = !x[123]|!x[129]|x[15];//not m_25_2 or not m_27 or o_4_3
	count_nodes_vector.push_back(x[541]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(542);
	std::cerr<<"Appending gate to output[1] x[541]"<<std::endl;
	output[1]=output[1] & x[541];
	
	std::cerr<<"processing gate 543..."<<std::endl;
	x[542] = !x[137]|!x[34]|!x[83];//not m_29 or not m_9_2 or not o_21_3
	count_nodes_vector.push_back(x[542]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(543);
	std::cerr<<"Appending gate to output[1] x[542]"<<std::endl;
	output[1]=output[1] & x[542];
	
	std::cerr<<"processing gate 544..."<<std::endl;
	x[543] = x[146]|!x[168]|x[172];//g_29_3_6 or not g_32_2_7 or m_36
	count_nodes_vector.push_back(x[543]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(544);
	std::cerr<<"Appending gate to output[1] x[543]"<<std::endl;
	output[1]=output[1] & x[543];
	
	std::cerr<<"processing gate 545..."<<std::endl;
	x[544] = !x[101]|!x[149]|x[47];//not g_24_2_4 or not g_29_3_9 or m_12_3
	count_nodes_vector.push_back(x[544]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(545);
	std::cerr<<"Appending gate to output[1] x[544]"<<std::endl;
	output[1]=output[1] & x[544];
	
	std::cerr<<"processing gate 546..."<<std::endl;
	x[545] = x[168]|x[39]|x[66];//g_32_2_7 or o_10_3 or o_18
	count_nodes_vector.push_back(x[545]);
	count_nodes.push_back(mgr.SharingSize(count_nodes_vector));
	count_id.push_back(546);
	std::cerr<<"Appending gate to output[1] x[545]"<<std::endl;
	output[1]=output[1] & x[545];
	//Null Function
	x[540] = mgr.bddOne();

	x[540] = x[540] & output[0];

	x[540] = x[540] & output[1];

  t2 = get_user_time();
  
  t4 = get_diftime(t1,t2);

  
  s_rootBDD =  x[540].getNode();
  


  

  


  //Calc minterms at end
  minTerms =  x[540].CountMinterm(175);



   
      sprintf(buffer,"%g\t%g\t%g",t4,t3,minTerms);
   



  




  str_output = "malik_fanin	NONE	0.0229970000";
  str_output = str_output + "\t" + buffer + "\t5761\t7.777777777777778\t175.0	185.0	2.0	54.0	65.05382386916237	54.0";
  
  print_output(547,"62_175.xml",str_output,mgr,output,true,&(x[540]),true);
  writeSize("growth.txt", "62_175.xml", "malik_fanin",count_nodes,count_id);

  




  kill(getppid(),SIGKILL);
  int status_parent;
  wait(&status_parent);
  exit(0);

}