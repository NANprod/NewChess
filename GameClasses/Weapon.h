#pragma once
#include <vector>
#include "Player.h"





class Weapon {
 protected:

  enum class Type { Melee, Distant };

  int weapon_id;
  int power;
  std::vector<Coord> hit_positions;
  Player* person;
  std::vector<Coord> hit_pattern;

 public:

  virtual std::vector<Coord> getWideHitPositions(const Coord&) abstract;
  virtual void updateHitPositions() abstract;
 //getters
  int getId() { return weapon_id; }
  int getPower() { return power; }
  std::vector<Coord> getHitPositions() { return hit_positions; }
  Player getPerson() { return *person; }
  std::vector<Coord> getHitPattern() { return hit_pattern; }
  
  //setters
  void setId(int id) { this->weapon_id = id; }
  void setPower(int power) { this->power = power; }
  void setHitPositions(std::vector<Coord> coord) {
    this->hit_positions = coord;
  }
  void setPerson(Player* person) { this->person = person; }
  void setHitPattern(std::vector<Coord> coord) { this->hit_pattern = coord; }
};


class MeleeWeapon : public Weapon {
 protected:
 
  struct RotateMatrix {
    double matrix[4];
    RotateMatrix() = delete;
  };

  const RotateMatrix r0 = RotateMatrix{1, 0, 0, 1};
  const RotateMatrix r90 = RotateMatrix{0, 1, -1, 0};
  const RotateMatrix r180 = RotateMatrix{-1, 0, 0, -1};
  const RotateMatrix r270 = RotateMatrix{0, -1, 1, 0};
  


 private:
  RotateMatrix getRotateMatrix(const Coord& hit) { 
    int x_difference = hit.x - person->getCoord().x;
    int y_difference = hit.y - person->getCoord().y;
    if (x_difference >= 0 && y_difference > 0) {
      return r0;
    }
    if (x_difference < 0 && y_difference >= 0) {
      return r90;
    }
    if (x_difference <= 0 && y_difference < 0) {
      return r180;
    }
    if (x_difference > 0 && y_difference <= 0) {
      return r270;
    }
  }


  Coord rotate(const Coord& c, const RotateMatrix& m) {
    int x  = m.matrix[0] * c.x + m.matrix[1] * c.y;
    int y = m.matrix[2] * c.x + m.matrix[3] * c.y;
    return Coord(x,y);
  }

 public:
  std::vector<Coord> getWideHitPositions(const Coord& hit) override {
    std::vector<Coord> coordinates;
    coordinates.reserve(hit_pattern.size());
    RotateMatrix rotate_matrix = getRotateMatrix(hit);
    for (auto& pattern_coord : hit_pattern) {


      Coord new_coord = rotate(pattern_coord, rotate_matrix);
      coordinates.push_back(new_coord + hit);
    }
    return coordinates;
  }
};

class DistantWeapon : public Weapon {
 public:
  virtual std::vector<Coord> getWideHitPositions(const Coord& hit) override {
    std::vector<Coord> coordinates;
    coordinates.reserve(hit_pattern.size());

    for (auto& cord : hit_pattern) {
      coordinates.push_back(cord + hit);
    }
    return coordinates;
  }
};