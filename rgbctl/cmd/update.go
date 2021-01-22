package cmd

import (
	"github.com/spf13/cobra"
	"github.com/2000Slash/rgbd/rgbctl/midlevel"
)

var updateCmd = &cobra.Command {
	Use:   "update",
	Short: "Updates the keyboard rgb with the currently set configuration.",
	Long: `The update command refreshes your keyboard configuration. It applies the currently set configuration from the daemon.`,
	Run: func(cmd *cobra.Command, args []string) {
		midlevel.Update();
	},
}

func init() {
	rootCmd.AddCommand(updateCmd)
}
