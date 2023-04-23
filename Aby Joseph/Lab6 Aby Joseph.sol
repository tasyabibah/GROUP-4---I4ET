//SPDX-License-Identifier: GPL-3.0
pragma solidity >=0.5.0 <0.8.0;
contract Factory {
    //Excercise 1
    uint idDigits = 16;
    //Excercise 2
    uint idModulus = 10**idDigits;

    //Excercise 3
    struct Product {
        string name;
        uint id; 
    }

    //Excercise 5
Product[] public products;

//Excercise 9
event NewProduct(uint ArrayProductId, string name, uint id);
    //Excercise 6
function _createProduct(string memory _name,uint _id) private 
{
        products.push(Product(_name,_id));
        uint productId= (products.length - 1);
        emit NewProduct(productId,_name,_id); 

}
    //Excercise 7
function _generateRandomId(string memory _str) private view returns (uint) {
     //Exercise 8
        uint rand = uint(keccak256(abi.encodePacked(_str)));
        return (rand%idModulus);
    }


function createRandomProduct(string memory _name) public {
        uint randId = _generateRandomId(_name);
        _createProduct(_name, randId);
    }



//Exercise 10
mapping (uint => address) public productToOwner;
mapping (address => uint) ownerProductCount;

function _Ownership (uint _productId) private { 
        productToOwner[_productId] = msg.sender;
        ownerProductCount[msg.sender]++;
    }

function getProductsByOwner (address _owner) external view returns(uint[] memory) { 
        uint counter=0;
        uint[] memory result= new uint[](ownerProductCount[_owner]);
        for (uint i=0; i<products.length; i++) {
            if (productToOwner[i]==_owner) {
                result[counter]=i;
                counter++;
            }
        }
        return result;              
    }

mapping (uint => uint) public age; 

modifier olderThan (uint _age, uint _userId) {
        require (age[_userId] >= _age, "You Must Be At Least 18 Years Old");
        _;
    }
    
    // Checking OpenZeppelin Solidity Library

function validationUsers (uint _userId) public olderThan(18, _userId) {
    }
}





