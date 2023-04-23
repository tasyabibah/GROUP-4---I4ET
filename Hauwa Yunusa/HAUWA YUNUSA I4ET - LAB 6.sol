//SPDX-License-Identifier: GPL-3.0  
pragma solidity >= 0.5.0 <0.8.0; 


contract Factory {  //Exercise 1

    uint idDigits = 16; //Exercise 2
    uint idModulus = 10**idDigits; //Exercise 3


struct Product {   //Exercise 4
    uint id;   
    string name;
    
} 

Product[] public products; //Exercise 5

uint[] id; //Exercise 6
function _createProduct(string memory _name,uint _id) private {   
    
} 

// Exercise 7 and 8
function _generateRandomId(string memory _str)  private view returns (uint) {   
    uint rand = uint(keccak256(abi.encodePacked(_str)));
    return (rand%idModulus);

    } 
function _createRandomProduct(string memory _name) public {
    uint randId = _generateRandomId(_name);
    _createProduct(_name,randId);
    
}

//Exercise 9
uint ArrayProductId;
string name;
uint Id;
event NewProduct(uint ArrayProductId, string name, uint Id); 
function _creatProduct (string memory _name, uint _Id) public {  
        uint productId = (products.length - 1);
        emit NewProduct (productId, _name, _Id);

}

//Exercise 10
mapping (uint => address) public productToOwner;
mapping (address => uint) ownerProductCount;

//Exercise 11
function _Ownership(uint _ProductId) private { 
    productToOwner [_ProductId] = msg.sender;     
    ownerProductCount [msg.sender]++;
}  

//Exercise 12

function _getProductsByOwner(address _owner) external view returns(uint [] memory) { 
    uint counter = 10;     
    uint[] memory result = new uint[] (ownerProductCount [_owner]);    
        for (uint i = 1; i < products.length; i++) {         
            if (productToOwner[i] == _owner) {         
                result [counter] = i;
                counter++;    
            } 
        }   
        return result;
}

//Exercise 14

mapping (uint => uint) public age;

    modifier olderThan (uint _age, uint _userId) {
    require (_userId >=   _age);
    _;

    }
function validationUsers (uint _userId) public view olderThan (18, _userId) {
}

}