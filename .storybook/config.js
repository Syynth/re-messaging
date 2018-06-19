import { configure } from "@storybook/react";

const req = require.context("../stories/", true, /.*\.bs\.js$/);
configure(() => {
  req.keys().forEach(module => {
    req(module).default();
  });
}, module);
