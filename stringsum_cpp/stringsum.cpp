#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "circom.hpp"
#include "calcwit.hpp"
void StringSum_0_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void StringSum_0_run(uint ctx_index,Circom_CalcWit* ctx);
void caculate_k_0(Circom_CalcWit* ctx,FrElement* lvar,uint componentFather,FrElement* destination,int destination_size);
void caculate_carry_1(Circom_CalcWit* ctx,FrElement* lvar,uint componentFather,FrElement* destination,int destination_size);
Circom_TemplateFunction _functionTable[1] = { 
StringSum_0_run };
uint get_main_input_signal_start() {return 257;}

uint get_main_input_signal_no() {return 512;}

uint get_total_signal_no() {return 769;}

uint get_number_of_components() {return 1;}

uint get_size_of_input_hashmap() {return 256;}

uint get_size_of_witness() {return 257;}

uint get_size_of_constants() {return 4;}

uint get_size_of_io_map() {return 0;}

// function declarations
void caculate_k_0(Circom_CalcWit* ctx,FrElement* lvar,uint componentFather,FrElement* destination,int destination_size){
FrElement* circuitConstants = ctx->circuitConstants;
FrElement expaux[3];
std::string myTemplateName = "caculate_k";
u64 myId = componentFather;
{
PFrElement aux_dest = &lvar[2];
// load src
Fr_add(&expaux[0],&lvar[0],&lvar[1]); // line circom 5
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[2],&circuitConstants[3]); // line circom 6
if(Fr_isTrue(&expaux[0])){
// return bucket
Fr_copy(destination,&lvar[2]);
return;
}else{
// return bucket
Fr_sub(&expaux[0],&lvar[2],&circuitConstants[3]); // line circom 9
Fr_copy(destination,&expaux[0]);
return;
}
}

void caculate_carry_1(Circom_CalcWit* ctx,FrElement* lvar,uint componentFather,FrElement* destination,int destination_size){
FrElement* circuitConstants = ctx->circuitConstants;
FrElement expaux[3];
std::string myTemplateName = "caculate_carry";
u64 myId = componentFather;
{
PFrElement aux_dest = &lvar[2];
// load src
Fr_add(&expaux[0],&lvar[0],&lvar[1]); // line circom 14
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[2],&circuitConstants[3]); // line circom 15
if(Fr_isTrue(&expaux[0])){
// return bucket
Fr_copy(destination,&circuitConstants[0]);
return;
}else{
// return bucket
Fr_copy(destination,&circuitConstants[2]);
return;
}
}

// template declarations
void StringSum_0_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 0;
ctx->componentMemory[coffset].templateName = "StringSum";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 512;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void StringSum_0_run(uint ctx_index,Circom_CalcWit* ctx){
FrElement* signalValues = ctx->signalValues;
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
FrElement* circuitConstants = ctx->circuitConstants;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
FrElement expaux[3];
FrElement lvar[3];
uint sub_component_aux;
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
{
PFrElement aux_dest = &lvar[1];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
{
PFrElement aux_dest = &lvar[0];
// load src
// end load src
Fr_copy(aux_dest,&circuitConstants[0]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[1]); // line circom 29
while(Fr_isTrue(&expaux[0])){
{
PFrElement aux_dest = &lvar[2];
// load src
Fr_add(&expaux[0],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[0])) + 256)],&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[0])) + 512)]); // line circom 30
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
{

// start of call bucket
FrElement lvarcall[3];
// copying argument 0
Fr_copy(&lvarcall[0],&lvar[2]);
// end copying argument 0
// copying argument 1
Fr_copy(&lvarcall[1],&lvar[1]);
// end copying argument 1
caculate_k_0(ctx,lvarcall,myId,&signalValues[mySignalStart + ((1 * Fr_toInt(&lvar[0])) + 0)],1);
// end call bucket
}

{

// start of call bucket
FrElement lvarcall[3];
// copying argument 0
Fr_copy(&lvarcall[0],&lvar[2]);
// end copying argument 0
// copying argument 1
Fr_copy(&lvarcall[1],&lvar[1]);
// end copying argument 1
caculate_carry_1(ctx,lvarcall,myId,&lvar[1],1);
// end call bucket
}

{
PFrElement aux_dest = &lvar[0];
// load src
Fr_add(&expaux[0],&lvar[0],&circuitConstants[2]); // line circom 29
// end load src
Fr_copy(aux_dest,&expaux[0]);
}
Fr_lt(&expaux[0],&lvar[0],&circuitConstants[1]); // line circom 29
}
}

void run(Circom_CalcWit* ctx){
StringSum_0_create(1,0,ctx,"main",0);
StringSum_0_run(0,ctx);
}

