#include "Chunk.h"

Chunk::Chunk(int row, int column) : row(row), column(column) {

}

Chunk::~Chunk() {

}

void Chunk::save(){
	string filename = "chunk " + to_string(row) + "_" + to_string(column);
	ofstream file(filename, ios::binary);

	size_t layers_count = layers.size();

	file.write(reinterpret_cast<const char*>(&layers_count),sizeof(layers_count));

	for (auto& layer : layers) {
		layer.save(file);
	}

	file.close();
}

void Chunk::load(SDL_Renderer* renderer) {
	string filename =  "chunk " + to_string(row) + "_" + to_string(column);
	ifstream file(filename, ios::binary);

	size_t layers_count;

	file.read(reinterpret_cast<char*>(&layers_count), sizeof(layers_count));

	int rows, columns;

	for (size_t i{ 0 }; i < layers_count; i++) {
		file.read(reinterpret_cast<char*>(&rows), sizeof(rows));
		file.read(reinterpret_cast<char*>(&columns), sizeof(columns));

		cout << "Columns: " << columns << ", rows: " << rows <<endl;

		layers.push_back(Layer(rows, columns));
		layers[i].load(renderer, file);
	}

	file.close();
}

void Chunk::add_layer(Layer layer) {
	layers.push_back(layer);
}