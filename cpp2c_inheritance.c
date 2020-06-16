#include <stdio.h>
#include "cpp2c_inheritance_defs.h"



void doMaterials()
{
	Materials mat;
	Material_t mat1;
    	Material_t mat2;
	struct MatTest { Materials mat; Material_t mat_t; };

    	printf("\n--- Start doMaterials() ---\n\n");
    	printf("Size of Materials: %lu\n", sizeof(Materials) + 1);
    	printf("Size of mat: %lu\n", sizeof(mat) + 1);
    	printf("Size of Materials::Types: %lu\n", sizeof(Types));
    	printf("Size of Material_t: %lu\n", sizeof(Material_t));
    	
    	printf("Size of Materials + Material_t: %lu\n", sizeof(Material_t) + sizeof(Material_t));
    	
	_ZN10Material_tC1EN9Materials5TypesE(&mat1, OTHER);
    	_ZN10Material_tC1EN9Materials5TypesE(&mat2, METAL);

    	printf("\n--- End doMaterials() ---\n\n");
}

void doPhysicalBox()
{
	PhysicalBox pb1;
	PhysicalBox pb2;
	PhysicalBox pb3;
	PhysicalBox pb4;

    	printf("\n--- Start doPhysicalBox() ---\n\n");

	_ZN11PhysicalBoxC1EdddN9Materials5TypesE(&pb1, 8, 6, 4, PLASTIC);
	_ZN11PhysicalBoxC1EN9Materials5TypesE(&pb2, WOOD);
	_ZN11PhysicalBoxC1Eddd(&pb3, 7, 7, 7);
    
    	printf("\npb4 is copy-constructed from pb1\n");
    	pb4 = pb1;
    	_ZNK11PhysicalBox6printpEv(&pb4);
    	_ZNK11PhysicalBox6printpEv(&pb1);
    	printf("pb4 %s pb1\n",  pb4.box.width == pb1.box.width && pb4.box.height == pb1.box.height && pb4.box.length == pb1.box.length && pb4.material.material == pb1. material.material ? "equals" : "does not equal");

    	printf("\npb4 is copy-assigned from pb3\n");
    	pb4 = pb3;
    	_ZNK11PhysicalBox6printpEv(&pb4);
    	_ZNK11PhysicalBox6printpEv(&pb3);
    	printf("pb4 %s pb3\n", pb3.box.width ==pb4.box.width && pb3.box.height == pb4.box.height && pb3.box.length == pb4.box.length && pb4. material.material == pb3. material.material ? "equals" : "does not equal");

    	printf("\n--- End doPhysicalBox() ---\n\n");
	
	_ZN11PhysicalBoxD1Ev(&pb4);
	_ZN11PhysicalBoxD1Ev(&pb3);
	_ZN11PhysicalBoxD1Ev(&pb2);
	_ZN11PhysicalBoxD1Ev(&pb1);
}

void doWeightBox()
{
	WeightBox pw1;
	WeightBox pw2;
	WeightBox pw3;
	WeightBox pw4;

    	printf("\n--- Start doWeightBox() ---\n\n");
    	
	_ZN9WeightBoxC1Edddd(&pw1, 8, 6, 4, 25);
	_ZN9WeightBoxC1Edddd(&pw2, 1, 2, 3, 0.0);
	_ZN9WeightBoxC1Edddd(&pw3, 10, 20, 30, 15);
    
    	printf("\npw4 is copy-constructed from pw1\n");
    	_ZN9WeightBoxC1ERKS_(&pw4, &pw1);
    	_ZNK9WeightBox6printwEv(&pw4);
    	_ZNK9WeightBox6printwEv(&pw1);
    	printf("pw4 %s pw1\n", pw4.box.width == pw1.box.width && pw4.box.height == pw1.box.height && pw4.box.length == pw1.box.length && pw4.weight == pw1.weight ? "equals" : "does not equal");

    	printf("\npw4 is copy-assigned from pw3\n");
    	_ZN9WeightBoxaSERKS_(&pw4, &pw3);
    	_ZNK9WeightBox6printwEv(&pw4);
    	_ZNK9WeightBox6printwEv(&pw3);
    	printf("pw4 %s pw3\n", pw4.box.width == pw3.box.width && pw4.box.height == pw3.box.height && pw4.box.length == pw3.box.length&& pw4.weight == pw3.weight ? "equals" : "does not equal");

    	printf("\n--- End doWeightBox() ---\n\n");
	
	_ZN9WeightBoxD1Ev(&pw4);
	_ZN9WeightBoxD1Ev(&pw3);
	_ZN9WeightBoxD1Ev(&pw2);
	_ZN9WeightBoxD1Ev(&pw1);
}





int main()
{
    	printf("\n--- Start main() ---\n\n");

    	doMaterials();

    	doPhysicalBox();

    	doWeightBox();

    	printf("\n--- End main() ---\n\n");
	return 0;

}
