#include "BinaryVisuals.h"

void BinaryVisuals::prepareBit(ViewPortGL& vp1, int xk, int yk, int width, int height, bool isOne) {
	if (isOne) {
		vp1.prepareBlock(xk, yk, width, height, 255, 255, 255);
	}
	else {
		vp1.prepareLine(xk, yk, xk + width, yk, 255, 255, 255);
		vp1.prepareLine(xk, yk, xk, yk + height, 255, 255, 255);
		vp1.prepareLine(xk + width, yk, xk + width, yk + height, 255, 255, 255);
		vp1.prepareLine(xk, yk + height, xk + width, yk + height, 255, 255, 255);
	}

}
void BinaryVisuals::prepareRepresentation(ViewPortGL& vp1, unsigned char value, int xk, int yk, int width, int height) {
	bool isOne = false, is_running = true;

	for (int i = 0; i < sizeof(unsigned char)*8; i++) {
		unsigned char comp = 0, mask = unsigned char(pow(2,i));
		comp = value & mask;
		if (comp == pow(2, i)) {
			isOne = true;
		}
		else {
			isOne = false;
		}
		prepareBit(vp1, xk, yk, width, height, isOne);
		xk -= (xpadding + width);
	}

	
}
void BinaryVisuals::prepareRepresentation(ViewPortGL& vp1, unsigned int value, int xk, int yk, int width, int height) {
	bool isOne = false;

	for (int i = 0; i < sizeof(unsigned int); i++) {
		unsigned int comp = 0, mask = unsigned int(pow(2, sizeof(unsigned char)*8))-1;
		comp = value >> i * 8;
		comp = comp & mask;
		unsigned char ch_val = comp;
		prepareRepresentation(vp1, unsigned char(ch_val), xk, yk, width, height);
		xk -= 8 * (width + xpadding) + 10;
	}
}

unsigned int BinaryVisuals::exchangeHalves(unsigned int value, int fromBit, int toBit) {
	//defining the parts to exchange as upper part (dividing_upper_bit til toBit) and lower part (fromBit til dividing_lower_bit)
	int upper_part = 0, lower_part = 0;
	unsigned int upper_mask = 0, lower_mask = 0, outer_mask = 0;
	int dividing_lower_bit = fromBit + (toBit - fromBit) / 2;
	int dividing_upper_bit = toBit - (toBit - fromBit) / 2;

	//calculation of the three masks used to separate the value
	for (int i = 0; i < sizeof(unsigned int) * 8; i++) {
		if (i <= toBit && i >= dividing_upper_bit) {
			upper_mask += unsigned int(pow(2, i));
		}
		if (i <= dividing_lower_bit && i >= fromBit) {
			lower_mask += unsigned int(pow(2, i));
		}
		if (i < fromBit || i > toBit) {
			outer_mask += unsigned int(pow(2, i));
		}
	}

	//upper part is the new lower part (fromBit til dividing_lower_bit)
	upper_part = (value & upper_mask) >> ((toBit - fromBit) / 2 + 1);

	//lower part is the new upper part (dividing_upper_bit til toBit)
	lower_part = (value & lower_mask) << ((toBit - fromBit) / 2 + 1);

	//combine all three values
	value = value & outer_mask | upper_part | lower_part;	

	return value;
}

unsigned int BinaryVisuals::reverse(unsigned int b) {
	int upper_bit = 0, lower_bit = 0, lower_index = 0, upper_index = 0, shift = 0;
	unsigned int upper_mask = 0, lower_mask = 0, outer_mask = 0;

	for (int i = 0; i < sizeof(unsigned int) * 8 / 2; i++) {
		lower_index = i;
		upper_index = sizeof(unsigned int) * 8 - i - 1;

		upper_mask = unsigned int(pow(2, upper_index));
		lower_mask = unsigned int(pow(2, lower_index));
		outer_mask = unsigned int(pow(2, sizeof(unsigned int) * 8) - 1) - upper_mask - lower_mask;

		shift = sizeof(unsigned int) * 8 - 2 * i - 1;

		upper_bit = (b & upper_mask) >> shift;
		lower_bit = (b & lower_mask) << shift;

		b = b & outer_mask | upper_bit | lower_bit;
	}

	return b;
}