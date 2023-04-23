//SPDX-License-Identifier: GPL -3.0
//excercise 1
pragma solidity >=0.5.0 <0.8.0;

//excercise 2
contract MyFirstExample {
uint idDigits = 16; 

//excercise 3
uint idModulus = 10 ** 2; // equal to 10^2

//excercise 4
struct Product {
uint id;
string name;
}

//excercise 5
Product[] public products;

//excercise 6
//function _createProduct(string memory _name, uint _id) private {
//}

//excercise 7 & 8
function _generateRandomId(string memory _str) private view returns (uint) {
uint rand = uint(keccak256(abi.encodePacked(_str)));
        return (rand%idModulus);
    } 
    function createRandomProduct(string memory _name) public {
        uint randId = _generateRandomId(_name); 
        _createProduct (_name, randId);
    } 

//excercise 9
// Use the Solidity event statement to define the event, give it a name, and define the data it passes when it triggers.
event NewProduct (uint ArrayProductId, string name, uint id);
function _createProduct (string memory _name, uint _id) private { //from excercise 6
        uint productId = (products.length - 1);
        emit NewProduct (productId, _name, _id); 
    }

//excercise 10
mapping (uint => address) public productToOwner;
mapping (address => uint) public ownerProductCount; 

//excercise 11
function _Ownership (uint _productId) private { 
        productToOwner [_productId] = msg.sender;
        ownerProductCount [msg.sender]++;
    }

//excercise 12
function _getProductsByOwner (address _owner) external view returns (uint[] memory) {
    uint counter =  0;
    uint[] memory result = new uint[] (ownerProductCount[_owner]);
     for (uint i=0; i<products.length; i++) {
            if (productToOwner[i]==_owner) {
                result[counter]=i;
                counter++;
            }
        }
        return result; 
}

//excercise 14
mapping (uint => uint) public age; 

    modifier olderThan (uint _age, uint _userId) {
        require (age[_userId] >= _age);
        _;
    }

    function validationUsers (uint _userId) public olderThan(18, _userId) {
    }

}