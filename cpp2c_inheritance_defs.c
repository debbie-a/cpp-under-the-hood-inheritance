#include <stdio.h>
#include "cpp2c_inheritance_defs.h"

void _ZN10Material_tC1EN9Materials5TypesE(Material_t *const this, Types mat)
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
	this->material = mat;
	printf("Material created, set to %s\n",names[this->material]);
	
}
/* PhysicalBox Defs */

void _ZN11PhysicalBoxC1Eddd(PhysicalBox *const this, double l, double w, double h)
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
	_ZN3BoxC1Eddd(&(this->box), l, w, h);
	this->material.material = OTHER;
	printf("Material created, set to %s\n",names[this->material.material]);
	_ZNK11PhysicalBox6printpEv(this);
}

void _ZN11PhysicalBoxC1EdddN9Materials5TypesE(PhysicalBox *const this, double l, double w, double h, Types t)
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
	_ZN3BoxC1Eddd(&(this->box), l, w, h);
	this->material.material = t;
	printf("Material created, set to %s\n",names[this->material.material]);
	_ZNK11PhysicalBox6printpEv(this);
}

void _ZN11PhysicalBoxC1EN9Materials5TypesE(PhysicalBox *const this,Types t)
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
	_ZN3BoxC1Ed(&(this->box), 1);
	this->material.material = t;
	printf("Material created, set to %s\n",names[this->material.material]);
    	_ZNK11PhysicalBox6printpEv(this);
	
}

void _ZN11PhysicalBoxD1Ev(const PhysicalBox *const this)
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    	printf("PhysicalBox dtor, %f x %f x %f, %s; ", this->box.length, this->box.width, this->box.height, names[this->material.material]);
	_ZN3BoxD1Ev(&(this->box));
}

void _ZNK11PhysicalBox6printpEv(const PhysicalBox *const this)
{
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    	printf("PhysicalBox, made of %s; ", names[this->material.material]);
    	_ZNK3Box5printEv(&(this->box));
}


/* WeightBox Defs */

void _ZN9WeightBoxC1Edddd(WeightBox *const this, double l, double w, double h, double wgt)
{
	_ZN3BoxC1Eddd(&(this->box), l, w, h);
	this->weight = wgt;
    	_ZNK9WeightBox6printwEv(this);
}

void _ZN9WeightBoxC1ERKS_(WeightBox *const this, const WeightBox *const other)  
{	
	_ZN3BoxC1Ed(&(this->box), 1);
	this->weight = other->weight;
    	_ZNK9WeightBox6printwEv(this);
}

void _ZN9WeightBoxD1Ev(const WeightBox *const this)
{
    	printf("Destructing WeightBox; ");
    	_ZNK9WeightBox6printwEv(this);
	_ZN3BoxD1Ev(&(this->box));
}

WeightBox* _ZN9WeightBoxaSERKS_(WeightBox *const this, const WeightBox *const other)
{
    	this->weight = other->weight;
    	return this;
}

void _ZNK9WeightBox6printwEv(const WeightBox *const this)
{
    	printf("WeightBox, weight: %f; ", this->weight);
    	_ZNK3Box5printEv(&(this->box));
}


