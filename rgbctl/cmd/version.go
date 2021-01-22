package cmd

import (
	"fmt"
	"github.com/spf13/cobra"
)

var versionCmd = &cobra.Command{
	Use:   "version",
	Short: "Print the version number of rgbctl",
	Long:  `Print the version number of rgbctl`,
	Run: func(cmd *cobra.Command, args []string) {
		fmt.Println("rgbctl version 1.0")
	},
}

func init() {
	rootCmd.AddCommand(versionCmd)
}
