package cmd

import (
	"github.com/spf13/cobra"
	"fmt"
)

var rootCmd = &cobra.Command {
	Use:   "rgbctl",
	Short: "Send control commands to the keyboard rgb daemon.",
	Long: `Rgbctl may be used to inspect or change the rgb Configuration set by the keyboard rgb daemon.`,
	Run: func(cmd *cobra.Command, args []string) {
		fmt.Println("Not yet implemented")
	},
}

func Execute() error {
	return rootCmd.Execute()
}
