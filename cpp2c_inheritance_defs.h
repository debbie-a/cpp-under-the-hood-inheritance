#ifndef __CPP2C_INHERITANCE_DEFS_H__
#define __CPP2C_INHERITANCE_DEFS_H__

#include <stdio.h>
#include "cpp2c_encapsulation_defs.h"

/* Materials */
typedef enum Types
{
        PLASTIC,
        METAL,
        WOOD,
        PAPER,
        OTHER
}Types;

typedef struct Materials
{
   
}Materials;


typedef struct Material_t /*:public Materials*/
{
    	Types material;

}Material_t;

/*Material_t(Types mat = OTHER): material(mat) { printf("Material created, set to %s\n", name()); }*/
void _ZN10Material_tC1EN9Materials5TypesE(Material_t *const, Types mat);


/* PhysicalBox */

typedef struct PhysicalBox /*:public Box*/
{
	Box box;
	Material_t material;

}PhysicalBox;


/* PhysicalBox Defs */

/*PhysicalBox(double l, double w, double h);*/
void _ZN11PhysicalBoxC1Eddd(PhysicalBox *const, double l, double w, double h);

/*PhysicalBox(double l, double w, double h, Materials::Types t);*/
void _ZN11PhysicalBoxC1EdddN9Materials5TypesE(PhysicalBox *const, double l, double w, double h, Types t);

/*PhysicalBox(Materials::Types t);*/
void _ZN11PhysicalBoxC1EN9Materials5TypesE(PhysicalBox *const,Types t);

/*~PhysicalBox();*/
void  _ZN11PhysicalBoxD1Ev(const PhysicalBox *const);

/*void printp() const;*/
void _ZNK11PhysicalBox6printpEv(const PhysicalBox *const);


/* WeightBox */

typedef struct WeightBox  /*: public Box*/
{
	Box box;
    	double weight;

}WeightBox;



/* WeightBox Defs */

/*WeightBox(double l, double w, double h, double wgt = 0.0);*/
void _ZN9WeightBoxC1Edddd(WeightBox *const, double l, double w, double h, double wgt);

/*WeightBox(const WeightBox& other);*/
void _ZN9WeightBoxC1ERKS_(WeightBox *const, const WeightBox *const other);

/*~WeightBox();*/
void _ZN9WeightBoxD1Ev(const WeightBox *const);

/*WeightBox& operator=(const WeightBox& other);*/
WeightBox* _ZN9WeightBoxaSERKS_(WeightBox *const, const WeightBox *const other);

/*void printw() const;*/
void _ZNK9WeightBox6printwEv(const WeightBox *const);

/*double getWeight() const;*/
void _ZNK9WeightBox9getWeightEv(const WeightBox *const);




#endif /*__CPP2C_INHERITANCE_DEFS_H__*/


