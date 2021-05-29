# frozen_string_literal: true

require 'test_helper'

class UsersControllerTest < ActionDispatch::IntegrationTest
  test 'запрос get new' do
    get signup_url
    assert_response :success
    assert_select 'title', 'Sign up|Simply'
  end
end

# user.yml empty
