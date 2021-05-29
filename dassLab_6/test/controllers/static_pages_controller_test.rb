# frozen_string_literal: true

require 'test_helper'

class StaticPagesControllerTest < ActionDispatch::IntegrationTest
  test 'запрос get help' do
    get help_url
    assert_response :success
    assert_select 'title', 'Help|Simply'
  end

  test 'запрос get about' do
    get about_url
    assert_response :success
    assert_select 'title', 'About|Simply'
  end
end
