package model

import 	"github.com/ethereum/go-ethereum/common"

type Log struct {
	Address common.Address `json:"address" gencodec:"required"`
	Topics []common.Hash `json:"topics" gencodec:"required"`
	Data []string `json:"data" gencodec:"required"`
	BlockNumber string `json:"blockNumber"`
	TxHash common.Hash `json:"transactionHash" gencodec:"required"`
	//TxIndex uint64 `json:"transactionIndex"`
	BlockHash common.Hash `json:"blockHash"`
	Index string `json:"logindex"`
	Removed bool `json:"removed"`
}