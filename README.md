# BlockChain 🧊⛓️
***Simplified centralized block chain implementation***

| 📖 Table Of Contents | link       |
|----------------------|------------|
| How it Works         | [here](#1) |
| Components           | [here](#2) |
| How to run           | [here](#3) |


## How it Works 🔍 <a name='1'></a>

### General overview
 1. Program starts with creation of Genesis Block
 2. While creating Genesis Block 1000 random Users are created
 3. Transaction Pool is populated with random transactions between Users
 4. Mining process starts after certain amount of Transactions is reached
 5. When proof of work is found new Block containing part of Transactions is created
 6. BlockChain validates solution and adds new Block to the BlockChain
 7. Process 4-6 is being repeated while Transaction Pool is not empty  
   &nbsp;
## Components <a name='2'></a>
  **User** - reprents one unique blockChain user \
  User contains:
   * Balance   - amount of funds User has
   * secretKey - private string used for signing transaction
   * publicKey - publicly available string used for validation of transaction signature
   - - -

  **Transaction** - represents movement of funds between balances of two different Users \
  Transaction contains: 
   * Unique Transaction ID
   * Sender information    (reference to User obj)
   * Receivers information (reference to User obj)
   * Senders Signature
   * double sum of transaction  
   - - -
   
   **Proof of Work** - is represented by a integer number, which when appended to the textual \
   representation  of last BlockChain Block and hashed, produces string the start of which \
   contains n amount of consequential 0 (n = difficulty Target) 
   - - - 
   
   **Block** - can be imagined as a page of a ledger, in other words Block is a way to store   
   certain amount of validated transactions \
   Block contains: 
   * Hash of previuos Block (if origin = "Origin")
   * Version Number
   * Time of Creation
   * Nonce - number used as Proof Of Work for previuous block (if orgin = -1)
   * Merkel Root Hash of validated transactions
   * Dificulty Target
   - - -
   
   **BlockChain** - a hash map of connected Blocks \
   {key = hash of Block, value = Block }
   - - -
   
## Examples 😓

## How to run 🛠️ <a name="3"></a>
### For Linux users ```make run```
### For Other OS  - TODO
