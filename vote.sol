//SPDX-License-Identifier: MIT

pragma solidity >= 0.8.0;

contract Election{
    struct candidate{
        uint id;
        string name;
        uint votecount;

    }
    mapping(address=>bool) public voters;

    mapping(uint=>candidate) public candidates;

    uint public candidatecount;
    event votedEvent(
        uint indexed candidateId
    );

    constructor(){
        addCandidate("candidate 1");
        addCandidate("candidate 2");
    }

    function addCandidate(string memory name) private {
        candidatecount++;
        candidates[candidatecount]= candidate(candidatecount, name, 0);
    }

    function vote(uint candid) public{
        require((!voters[msg.sender]));
        require(candid >0 && candid <=candidatecount);
        voters[msg.sender]=true;
        candidates[candid].votecount++;
        emit votedEvent(candid);
    }

}